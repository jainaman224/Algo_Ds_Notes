<?php

class AVLTree 
{
    var $left;
    var $right;
    var $depth;
    var $data;
   
    function AVLTree() 
    {
        $this->left = NULL;
        $this->right = NULL;
        $this->depth = 0;
        $this->data = NULL;
    }
   
    function balance() 
    {
        $ldepth = $this->left !== NULL
                ? $this->left->depth
                : 0;
               
        $rdepth = $this->right !== NULL
                ? $this->right->depth
                : 0;
               
               
        if( $ldepth > $rdepth+1 ) 
        { // LR or LL rotation
            $lldepth = $this->left->left !== NULL
                     ? $this->left->left->depth
                     : 0;

            $lrdepth = $this->left->right !== NULL
                     ? $this->left->right->depth
                     : 0;

            if( $lldepth < $lrdepth ) 
            { // LR rotation
                $this->left->rotateRR(); // consist of a RR rotation of the left child ...
            } // ... plus a LL rotation of this node, which happens anyway

            $this->rotateLL();
        } 
        else if( $ldepth+1 < $rdepth ) 
        { // RR or RL rorarion
            $rrdepth = $this->right->right !== NULL
                     ? $this->right->right->depth
                     : 0;

            $rldepth = $this->right->left !== NULL
                     ? $this->right->left->depth
                     : 0;

            if( $rldepth > $rrdepth ) 
            { // RR rotation
                $this->right->rotateLL(); // consist of a LL rotation of the right child ...
            } // ... plus a RR rotation of this node, which happens anyway

            $this->rotateRR();
        }
    }
   
    function rotateLL() 
    { // the left side is too long => rotate from the left (_not_ leftwards)
        $data_before =& $this->data;
        $right_before =& $this->right;
       
        $this->data =& $this->left->data;
        $this->right =& $this->left;
        $this->left =& $this->left->left;
        $this->right->left =& $this->right->right;
        $this->right->right =& $right_before;
        $this->right->data =& $data_before;
        $this->right->updateInNewLocation();
        $this->updateInNewLocation();
    }
   
    function rotateRR() 
    { // the right side is too long => rotate from the right (_not_ rightwards)
        $data_before =& $this->data;
        $left_before =& $this->left;
       
        $this->data =& $this->right->data;
        $this->left =& $this->right;
        $this->right =& $this->right->right;
        $this->left->right =& $this->left->left;
        $this->left->left =& $left_before;
        $this->left->data =& $data_before;
        $this->left->updateInNewLocation();
        $this->updateInNewLocation();
    }
   
    // -- updateInNewLocation
    // may be overloaded by derived class
    function updateInNewLocation() 
    {
        $this->getDepthFromChildren();
    }
   
   
    function getDepthFromChildren() 
    {
        $this->depth = $this->data !== NULL ? 1 : 0;
        if( $this->left !== NULL )
            $this->depth = $this->left->depth+1;
        if( $this->right !== NULL && $this->depth <= $this->right->depth )
            $this->depth = $this->right->depth+1;
    }

    // --- debugging functions
       
    function toString() 
    {
        $s = "<table border><tr>\n".$this->toTD(0)."</tr>\n";
        $depth = $this->depth-1;
        for( $d = 0; $d < $depth; ++$d ) 
        {
            $s .= "<tr>";
           
            $s .= $this->left !== NULL
                ? $this->left->toTD( $d )
                : "<td></td>";
               
            $s .= $this->right !== NULL
                ? $this->right->toTD( $d )
                : "<td></td>";
               
            $s .= "</tr>\n";
        }
       
        $s .= "</table>\n";
        return $s;
    }
   
    function toTD( $depth ) 
    {
        if( $depth == 0 ) 
        {
            $s = "<td align=center colspan=".$this->getNLeafs().">";
            $s .= $this->data."[".$this->depth."]</td>\n";
        } 
        else 
        {
            if( $this->left !== NULL ) 
            {
                $s = $this->left->toTD( $depth-1);
            } 
            else 
            {
                $s="<td></td>";
            }

            if( $this->right !== NULL ) 
            {
                $s .= $this->right->toTD( $depth-1);
            } 
            else 
            {
                if( $this->left !== NULL )
                    $s.="<td></td>";
            }
        }
       
        return $s;
    }
   
    function getNLeafs() 
    {
        if( $this->left !== NULL ) 
        {
            $nleafs = $this->left->getNLeafs();
           
            if( $this->right !== NULL )
                $nleafs += $this->right->getNLeafs();
            else
                ++$nleafs; // lus one for the right "stump"
        } 
        else 
        {
            if( $this->right !== NULL )
                $nleafs = $this->right->getNLeafs()+1; // plus one for the left "stump"
            else
                $nleafs = 1; // this node is a leaf
        }
       
        return $nleafs;
    }
   
}
?>

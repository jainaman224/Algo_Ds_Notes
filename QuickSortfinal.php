<?php
	
	//taking array
	print "<form method=post action=QuickSortfinal.php>";
	for($i=0;$i<5;$i++)
	{
		print"<input type=text name=txt$i size=5 />";
	}
		print "<input type=submit value=Submit />";
	print"</form>

	$unsortedArray = array();
	if(isset($_POST[txt0]))
	{
		for($i=0;$i<5;$i++)
		{
			$unsortedArray[$i]=$_POST['txt'.$i];
		}
		print "<pre>";
		print_r($unsortedArray);
		print "</pre>";
	}

	
	$low = 0;
	$high = sizeof($unsortedArray)-1;

	//getting the desired output
	$unsortedArray = quickSort($unsortedArray,$low,$high);
	for($i=0;$i<=$high;$i++){
		echo $unsortedArray[$i];
	}

	//The source code for quicksort

	function quickSort($unsortedArray,$low,$high){
	if($low < $high){
			$endIndexOfArray= partitionOfArray($unsortedArray,$low,$high);
			
			quickSort($unsortedArray,$low,$endIndexOfArray - 1);
			quickSort($unsortedArray,$endIndexOfArray + 1,$high);
		}
		return $unsortedArray;
	}

	/*Selecting a pivot element and swapping around it till we get numbers <pivot element on 
	left and numbers > pivot element on its right*/
	function partitionOfArray($unsortedArray,$low,$high){
		$startIndexOfArray = $low;
		$endIndexOfArray = $high;
		$pivotElement = $startIndexOfArray;
		while($startIndexOfArray < $endIndexOfArray){
			while($unsortedArray[$startIndexOfArray] <= $unsortedArray[$pivotElement]){
				$startIndexOfArray++;
			}
			while($unsortedArray[$endIndexOfArray] > $unsortedArray[$pivotElement]){
				$endIndexOfArray--;
			}
			
			if($startIndexOfArray < $endIndexOfArray){
				swap($unsortedArray,$startIndexOfArray,$endIndexOfArray);
			
			}
		}
			$unsortedArray = swap($unsortedArray,$low,$endIndexOfArray);
			return $endIndexOfArray;
	}
	function swap($unsortedArray,$low,$endIndexOfArray){
		$temp = $unsortedArray[$low];
		$unsortedArray[$low] = $unsortedArray[$endIndexOfArray];
		$unsortedArray[$endIndexOfArray] = $temp;
		
		return $unsortedArray;
	}
?>

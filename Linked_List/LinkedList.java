
import java.io.*;
import java.util.*;
import java.lang.*;

public class LinkedList {
    private Node Start;
    
    
    class Node{
        public String info;
        public Node next;
       
        public Node(String s){
            info = s;
            next = null;
        }
    }
    
    public void Insert_position(int pos, String val){                      // METHOD FOR INSERTING A NODE AT A GIVEN POSITION IN LL
        int act_pos = pos-1;
        if(act_pos == 0){
         
            Node temp = new Node(val);
            if(Start == null){
                Start = temp;
            }
            else{
                temp.next = Start;
                Start = temp;
            }
            
        }
        else{
            Node temp = new Node(val);
            temp.next = Start;
            Node p = temp;
            for(int z = 0; z < act_pos; ++z){
                p = p.next;
            }
            Node q  = new Node(val);
            q.info = val;
            q.next = p.next;
            p.next = q;
        }
    }
    
    public void Deletion_LinkedList(int pos){                               // METHOD FOR DELETING A NODE AT A POSITION FROM THE LINKED LIST
        int act_pos = pos - 1;
        if(act_pos == 0){
            Node temp = Start;
            Start = temp.next;
            temp.next = null;
        }
        else{
            Node temp = Start;
            for(int g = 0; g < act_pos-1 && temp != null; g++){
                temp = temp.next;   
            }
            Node p = temp.next.next;
            temp.next = p;
        }
    }
    
    public void Insertion_LinkedList(String val){                         // METHOD FOR APPENDING VALUES TO A LINKED LIST.
        Node temp1 = new Node(val);
        if(Start == null){
            Start = temp1;
        }
        else{
            Node temp2 = Start;
            while(temp2.next != null){
                temp2 = temp2.next;
            }
            temp2.next = temp1;
        }
    }
    
    public void Display(){                                                 // METHOD FOR DISPLAYING THE LINKED LIST
        Node now = Start;
        while(now != null){
            System.out.print(now.info + " ");
            now = now.next;
        }
        System.out.println("");
       
        
    }
    
    
    public void Compare(LinkedList ob){                                    // METHOD FOR COMPARING THE LINKED LIST
        
        Node temp1 = this.Start;
        Node temp2 = ob.Start;
        while(temp1 != null && temp2 != null){
            if(!(temp1.info.equals(temp2.info)) == true){
                System.out.println("0");
                break;
            }
            temp1 = temp1.next;
            temp2 = temp2.next;
        
        }
        if((temp1 == null) && (temp2 == null)){
            System.out.println("1");
            
        }
        else if((temp1 == null) || (temp2 == null)){
            System.out.println("0");
        }
    }
    
    
    public static void main(String[] args) throws Exception {                // BEGINNING OF MAIN MODULE   
        InputStreamReader r = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(r);
        String t = br.readLine();
        String[] tokens = t.split(" ");
        int[] a = new int[tokens.length];
        for(int i = 0; i < tokens.length; i++){
            a[i] = Integer.parseInt(tokens[i]);
        }
        LinkedList ll = new LinkedList();
        String[] b = new String[a[0]];
        String arr1 = br.readLine();
        String[] split_arr = arr1.split(" ");
        for(int j = 0; j < split_arr.length; j++){
            ll.Insertion_LinkedList(split_arr[j]);
            
        }
        for(int m = 0; m < a[1]; m++){
            
            String q = br.readLine();
	    String[] query_arr = q.split(" ");
	    String [] c = new String[query_arr.length];
	    for(int l = 0; l < query_arr.length; l++){
		c[l] = query_arr[l];
	    }
            if(Integer.parseInt(c[0]) == 1){
                ll.Insert_position(Integer.parseInt(c[2]), c[1]);
            }
            else if(Integer.parseInt(c[0]) == 2){
                ll.Deletion_LinkedList(Integer.parseInt(c[1]));
            }
            else if(Integer.parseInt(c[0]) == 3){
                ll.Display();
            }
            else{
                if(Integer.parseInt(c[0]) == 4){
                LinkedList ll2 = new LinkedList();
                for(int d = 2; d <= c.length-1; d++){
                    ll2.Insertion_LinkedList(c[d]);
                }
                
                ll.Compare(ll2);
                
                }
            }
        }
    }
}

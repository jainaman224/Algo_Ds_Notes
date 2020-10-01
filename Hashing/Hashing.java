//Closed hashing techniques using linear (with and without replacement) and quadratic probing and double hashing techniques
package closedHashing;
import java.util.*;

public class ClosedHashing 
{
    public static void main(String args[])
    {
        int n = 5;      //number of elements to be inserted in hash table
        Hash h = new Hash();
        h.acceptElements(n);
    }
}

class Hash
{
    int hashtable1[] = new int[10]; //hash table of size 50, technique for probing is linear probing
    int hashtable2[] = new int[10]; //hash table of size 50, technique for probing is linear probing with replacement
    int hashtable3[] = new int[10]; //hash table of size 50, technique for probing is quadratic probing
    int hashtable4[] = new int[10]; //hash table of size 50, technique is double hashing
    
    //good load factor is <=0.5
    //default constructor
    hash()
    {
        for (int i = 0; i < 10; i++)
        {
            hashtable1[i] = -1; //initialized to indicate no element currently 
            hashtable2[i] = -1;
            hashtable3[i] = -1;
            hashtable4[i] = -1;
        }
    }
    Scanner sc=new Scanner(System.in);
    
    //function to accept elements
    void acceptElements(int n)
    {
        for (int i = 0; i < n; i++)
        {
            int element = sc.nextInt();
            insertLP(element);
            insertLPWR(element);
            insertQP(element);
            insertDH(element);
        }
        
        //display the different hash tables after hashing performed
        System.out.println("\nLinear Probing without replacement:");    
        display(n, hashtable1);
        System.out.println("\nLinear Probing with replacement:");
        display(n, hashtable2);
        System.out.println("\nQuadratic Probing:");
        display(n, hashtable3);
        System.out.println("\nDouble Hashing:");
        display(n, hashtable4);
    }
    
    //pass every element to the hash function to find its hash address
    int hashfunction(int n)
    {
        int hno = n % 10;
        return hno;
    }
    
    //linear probing without replacement
    void insertLP(int element)
    {
        int flag = 0;
        int hashaddress = hashfunction(element);    //found hash address for element
        if (hashtable1[hashaddress] == -1)  //i.e. position currently empty
        {
            hashtable1[hashaddress] = element;  //element inserted at appropriate position
        }
        else
        {
            int lp = (hashaddress + 1) % 10;    //linear probing applied to look for empty space
            while(flag != 1)
            {
                //found empty position?
                if (hashtable1[lp] == -1)
                {
                    hashtable1[lp] = element;
                    flag = 1;
                }
                else
                    lp = (lp + 1) % 10; //else, keep looking
            }
        }
    }
    
    //linear probing with replacement
    void insertLPWR(int element)
    {
        int flag = 0;
        int temp = element;
        int hashaddress = hashfunction(element);    //found hash address for element
        if (hashtable2[hashaddress] == -1)  //i.e. position currently empty
        {
            hashtable2[hashaddress] = element;  //element inserted at appropriate position
        }
        else
        {
            int lp = (hashaddress + 1) % 10;    //linear probing applied to look for empty space for element
            int hold = hashfunction(hashtable2[hashaddress]);   //found hash address of key already present at the collided index
            if (hold != hashaddress)    //i.e. not its original address
            {
                //then, find new hash address for element originally present
                temp = hashtable2[hashaddress];
                hashtable2[hashaddress] = element;
            }
            while (flag != 1)
            {
                //found empty position?
                if (hashtable2[lp] == -1)
                {
                    hashtable2[lp] = temp;
                    flag = 1;
                }
                else
                    lp = (lp + 1) % 10; //else, keep looking
            }
        }   
    }
    
    //quadratic probing without replacement
    void insertQP(int element)
    {
        int flag = 0;
        int hashaddress = hashfunction(element);    //found hash address for element
        if (hashtable3[hashaddress] == -1)  //i.e. position currently empty
        {
            hashtable3[hashaddress] = element;  //element inserted at appropriate position
        }
        else
        {
            int lp = (hashaddress + 1) % 10;    //probing applied to look for empty space
            int i = 2;
            while (flag != 1)
            {
                //found empty position?
                if (hashtable3[lp] == -1)
                {
                    hashtable3[lp] = element;
                    flag = 1;
                }
                else
                {
                    lp = (lp + (i ^ 2)) % 10;   //else, keep looking quadratically incremented
                    i++;
                }
            }
        }
    }
    //double hashing
    void insertDH(int element)
    {
        int offset = 7 - (element % 7);     //second hash function
        int flag = 0;
        int hashaddress = hashfunction(element);    //found hash address for element
        if (hashtable4[hashaddress] == -1)  //i.e. position currently empty
        {
            hashtable4[hashaddress] = element;  //element inserted at appropriate position
        }
        else
        {
            while (flag != 1)
            {
                hashaddress = (hashaddress + offset) % 10;  //hash address changed
                if (hashtable4[hashaddress] == -1)  //i.e. position currently empty
                {
                    hashtable4[hashaddress] = element;  //element inserted at appropriate position
                    flag = 1;
                }
            }
        }
    }
    
    //display elements in hashtable
    void display(int n, int hashtable[])
    {
        System.out.println("\nIndex\tElement");
        for (int i = 0; i< 10; i++)
        {
            if (hashtable[i] != -1)
            {
                System.out.println(i + "\t" + hashtable[i]);
            }
        }
    }
}
/*
Input:
44
3
34
77
23

Output:
Linear Probing without replacement:

Index   Element
3       3
4       44
5       34
6       23
7       77

Linear Probing with replacement:

Index   Element
3       3
4       44
5       34
6       23
7       77

Quadratic Probing:

Index   Element
1       23
3       3
4       44
5       34
7       77

Double Hashing:

Index   Element
3       3
4       44
5       34
7       77
8       23
*/

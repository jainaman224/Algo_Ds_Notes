/*  This is code for hashing using chaining. 
    It creates a symbol table (basically array of objects of symbolTableEntry type). 
    Each entry consists of indentifier(name) and attribute pair.

    Hash function :- hashValue  =  key % size_of_table

    Program includes following functionality - 
    1. Insert entry 
		a. With replacement
		b. Without replacement
    2. Delete entry
    3. Search entry
    4. Get attribute
    5. Update attribute
    6. Display symbol table
*/

#include <iostream>
using namespace std;

class symbolTableEntry
{
    string name, attr;
    symbolTableEntry *next;
public:
    symbolTableEntry()
    {
        name = "NULL";
        attr = "NULL";
        next = NULL;
    }
    friend class symbolTable;
};

//Symbol table is basically array of objects of symbolTableEntry type
class symbolTable
{
    //Size  =  No. of elements in array 
    //maxSize  =  MAX allowed elements in table	
    int size, maxSize;							
    symbolTableEntry table[2000];
public:
    symbolTable()
    {
        size = 0;
        maxSize = 0;
    }

    //Function to display all symbol table entries
    void traverse()		
    {
        symbolTableEntry *n;
        cout << "\ni  Name" << "  Attr  " << endl;
        for (int i = 0; i < size; i++)
        {
            n = table[i].next;
            cout << "\n" << i << "  " << table[i].name << "  " << table[i].attr;
            while(n != NULL)
	        {
	            cout << "\n" << i << "  " << n -> name << "  " << n -> attr;
		        n = n -> next;
	        }
	    }
    } 

    void search()
    {
        symbolTableEntry *n;
        string name;
	    int key, hash;
	    cout << "\nEnter attribute name : ";
	    cin >> name;
		
        //Find hash value for this key
	    key = 0;
	    for (int i = 0; i < name.length(); i++)
	        key = key + name[i];

        //Now key contains required ASCII value of entered name.
        hash  =  key % size;

        //Name found at hash address.
        if (table[hash].name.compare(name) == 0)  
        {
            cout << "\nFOUND\n";
        }
        else
        {
            //Searching name in chain at calculated hash addrss.
            n = table[hash].next;    
            while(n != NULL)
            {
                if (n -> name.compare(name) == 0)
                {
                    cout << "\nFOUND\n";	
                    break;
                }
                n = n -> next;
            }
            if (n == NULL)
                cout << "\nNOT FOUND";			
        } 
    }

    void getAttribute()
    {
        symbolTableEntry *n;
        string name;
        int key, hash;
        cout << "\nEnter attribute name : ";
        cin >> name;

        //Find hash value for this key
        key = 0;
        for (int i = 0; i < name.length(); i++)
                key = key + name[i];
        hash = key % size;

        //Name found at hash address.
        if (table[hash].name.compare(name) == 0)  
        {
            cout << "\nAttribute  =  " << table[hash].attr;
        }
        else 								   
        {
            //Searching name in chain at calculated hash address.
            n = table[hash].next;		
            while(n != NULL)
            {
                //Name found, attribute value printed
                if (n -> name.compare(name) == 0)	
                {
                    cout << "\nAttribute  =  " << n -> attr;
                    break;
                }
                n = n -> next;
             }
             if (n == NULL)
                 cout << "\nNOT FOUND";			
        } 
    }	
	
    void updateAttribute()
    {
        symbolTableEntry *n;
        string name, attr;
        int key, hash;

        cout << "\nEnter name : ";
        cin >> name;		

        //Find hash value for this key
        key = 0;
        for (int i = 0; i < name.length(); i++)
            key = key + name[i];

        hash = key % size;

        //Entry found
        if (table[hash].name.compare(name) == 0)  
        {
            cout << "\nEnter new attribute : ";
            cin >> attr;		
            //Entry updated
            table[hash].attr = attr;				
        }
        else
        {
            n = table[hash].next;		
            while(n != NULL)
            {
                if (n -> name.compare(name) == 0)			
                {
                    //Entry found in chain at calculated hash address
                    cout << "\nEnter new attribute : ";
                    cin >> attr;		
                    //Entry updated
                    n -> attr = attr;						
                    break;
                }
                n = n -> next;
            }
            if (n == NULL)
                cout << "\nNOT FOUND";			
        } 
    }	
	
    void getSize()
    {
        cout << "\nEnter size of table : ";
        cin >> size;
    }

    void withReplacement() 
    {
        char ch = 'n';
        int hash, ptr, key;
        string name, attr;
        symbolTableEntry *p, *q, *n;

        do
        {
            cout << "\nEnter attribute name : ";
            cin >> name;
            cout << "\nEnter attribute value : ";
            cin >> attr;

            //Find hash value for this key
            key = 0;
            for (int i = 0; i < name.length(); i++)
            key = key + name[i];
            hash = key % size;

            //Table entry is empty, insert the new entry directly	
            if (table[hash].name.compare("NULL") == 0)  
            {
                table[hash].name = name;
                table[hash].attr = attr;
                cout << "\nINSERTED\n";
            }
            else						
            {
                n = new symbolTableEntry();
                n -> next = table[hash].next;
                table[hash].next = n;
                n -> name = table[hash].name;
                n -> attr = table[hash].attr;
                table[hash].name = name;
                table[hash].attr = attr;
                cout << "\nINSERTED\n";
            } 
            cout << "\nWant to add more(y|n) : ";
            cin >> ch;
        }while(ch == 'y');
    }
	
    void withoutReplacement()
    {
        char ch = 'n';
        int hash, ptr, key;
        string name, attr;
        symbolTableEntry *p, *q, *n;
        do
        {
            cout << "\nEnter attribute name : ";
            cin >> name;
            cout << "\nEnter attribute value : ";
            cin >> attr;

            //Find hash value for this key
            key = 0;
            for (int i = 0; i < name.length(); i++)
                key = key + name[i];
            hash = key % size;

            //Table entry is empty, insert the new entry directly
            if (table[hash].name.compare("NULL") == 0)  
            {
                table[hash].name = name;
                table[hash].attr = attr;
            }
            else					    
            {
                //Table entry not empty, so add the new entry at the end of chain.    
                p = table[hash].next;
                if (p != NULL)
                {
                    while(p -> next != NULL)
                    {
                        p = p -> next;
                    }
                }
                else
                {
                    p = &(table[hash]);
                }

                n = new symbolTableEntry();
                p -> next = n;
                n -> name = name;
                n -> attr = attr;
                cout << "\n" << n -> name << "  " << n -> attr;
            }
            cout << "\nWant to add more(y|n) : ";
            cin >> ch;
        }while(ch == 'y');
    }

    void deleteEntry()
    {
        symbolTableEntry *n, *p;
        string name;
        int key, hash;
        cout << "\nEnter name of attribute to delete : ";
        cin >> name;

        //Find hash value for this key
        key = 0;
        for (int i = 0; i < name.length(); i++)
            key = key + name[i];
        hash = key % size;

        //Required name found at hash address.
        if (table[hash].name.compare(name) == 0)            
        {
            //Only one entry available at this hash address	
            if (table[hash].next == NULL)        
            {
                table[hash].name = "NULL";
                table[hash].attr = "NULL";
            }
            else						
            {
                //Multiple entries available at this hash address    
                n = table[hash].next;
                table[hash].attr = n -> attr;
                table[hash].name = n -> name;
                table[hash].next = n -> next;
                delete n;
            } 
            cout << "\nDELETED\n";
        }	
        else			
        {
            //Entry not present in table, present in chain
            p = &(table[hash]);
            n = table[hash].next;
            if(n == NULL)
            	cout << "\nNOT FOUND";				
            else	
            {
	            while(n -> next != NULL && !(n -> name.compare(name) == 0))
	            {
	                p = n;
	                n = n -> next;
	            }
	            
	            //Required name found in chain at hash address.	
	            if (n -> name.compare(name) == 0)	
	            {
	                p -> next = n -> next;
	                delete n;
	                cout << "\nDELETED";				
	            }
	            else
	            	cout << "\nNOT FOUND";				
			}
        }     
	}
};

int main() {
    symbolTable symTable;
    int choice, insertChoice = 0;
    cout << "\n\n\n************************** SYMBOL TABLE *************************\n";

    symTable.getSize();

    cout << "\n\nInsertion method :- \n\t1. With replacement \n\t2. Without replacement\nEnter choice : ";
    cin >> insertChoice;

    do{		
        cout << "\n\nMENU\n\n";
        cout << " 1. Insert\n 2. Delete\n 3. Search\n 4. Get attribute\n 5. Update attribute \n 6. Display table \n 7. Exit\n";
        cout << "\nEnter your choice\n";
        cin >> choice;
        cout << endl;	
        
        switch(choice){
            case 1 :
                if (insertChoice == 1)
                    symTable.withReplacement();
                else
                    symTable.withoutReplacement();
                break;
            case 2 :
                symTable.deleteEntry();
                break;
            case 3 :
                symTable.search();
                break;
            case 4 :
                symTable.getAttribute();
                break;
            case 5 :
                symTable.updateAttribute();
                break;
            case 6 :
                symTable.traverse();
                break;
            case 7 :
                exit(0);
                break;	
            default :
                printf("Enter correct choice\n");
                break;
        }
    } while(choice);
    return 0;
}

/*
    Sample Input/output -	
    ************************** SYMBOL TABLE *************************
    A. Enter size of table : 5
    B. Insertion method :- 
        1. With replacement 
	    2. Without replacement
	    Enter choice : 1
    C. MENU
        1.Insert
        2.Delete
        3.Search
        4.Get attribute
        5.Update attribute
        6.Display table
        7.Exit
	
    1. Choice 1 - Enter attribute name : proc_name
        Enter attribute value : sum
        INSERTED
    
    2. Choice 1 - Enter attribute name : var_name
        Enter attribute value : num1
        INSERTED
   
    3. Choice 6 - SYMBOL TABLE
        i Name Attr
        0 NULL NULL
        1 var_name num1
        2 NULL NULL
        3 proc_name sum
        4 NULL NULL
	
    4. Choice 4 -  (Get Attribute)
        Enter attribute name : proc_name
        Attribute : sum
	
    5. Choice 3 -  (Search)
        Enter attribute name : var_name
        FOUND
	
    6. Choice 2 -  (Delete)
        Enter attribute name : var_name
        DELETED
	
    7. Choice 6 - SYMBOL TABLE
        i Name Attr
        0 NULL NULL
        1 NULL NULL
        2 NULL NULL
        3 proc_name sum
        4 NULL NULL
*/

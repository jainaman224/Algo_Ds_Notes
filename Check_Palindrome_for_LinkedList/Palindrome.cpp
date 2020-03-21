#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
    
public:
    string data;
    Node *next;
};

Node *start;


/*Function to insert values to the linked_list at the end*/
void insert_end()
{
    Node *p = start;
    Node *temp = new Node();
    string item;

    cout << "ENTER ITEM:" << endl;
    cin >> item;
    temp->data = item;
    
    if (start == NULL)
    {
        start = temp;
        temp->next = NULL;
    }
    
    else
    {
        
        while (p->next != NULL)
        {
            p = p->next;
        }
        
        p->next = temp;
        temp->next = NULL;
    }
    
}


/*Function to display the Linked List*/
void display()
{
    struct Node *p = start;
    cout << " YOUR LINKED LIST LOOKS LIKE :" << endl;
    cout << "|_START";
    
    while (p != NULL)
    {
        cout << " |_" << p->data << "_|_|->";
        p = p->next;
    }
    
    cout << "[NULL]" << endl;
}


/*Function to check whether a string is palindrome or not*/
bool palindrome(string str)
{
    string strc=str;
    std::reverse(str.begin(),str.end());

    if(str==strc)
        return true;
    
    return false;
}


/*Function to check whether LinkedList Data is Palindrome or not*/
bool isPalindrome()
{
    Node *p=start;
    string copy="";
    
    while(p!=NULL)
    {
        copy.append(p->data);
        p=p->next;
    }
    
    return palindrome(copy);
}


int main()
{
    int choice;
    cout << "PUSH ELEMENTS ONE BY ONE  INTO THE LINKED LIST:" << endl;
    int count = 0;

    int will;
    
    while (will)
    {
        insert_end();
        cout << "ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:" << endl;
        cin >> will;
    }
    
    display();
    
    bool result = isPalindrome();
    
    if(result==true)
    {
        cout<<"Palindrome"<<endl;
    }
    
    else
    {
        cout<<"Not a Palindrome"<<endl;
    }
    
    return 0;
}

/*input/output Demo 1:
PUSH ELEMENTS ONE BY ONE  INTO THE LINKED LIST:
ENTER ITEM:
1
ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:
1
ENTER ITEM:
ab
ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:
1
ENTER ITEM:
dba
ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:
1
ENTER ITEM:
1
ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:
0
 YOUR LINKED LIST LOOKS LIKE :
 |_START |_1_|_|-> |_ab_|_|-> |_dba_|_|-> |_1_|_|->[NULL]
 Palindrome
input/output Demo 2:
PUSH ELEMENTS ONE BY ONE  INTO THE LINKED LIST:
ENTER ITEM:
1
ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:
1
ENTER ITEM:
ab
ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:
1
ENTER ITEM:
dca
ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:
1
ENTER ITEM:
1
ENTER 1 TO CONTINUE INSERTING AND 0 TO STOP:
0
 YOUR LINKED LIST LOOKS LIKE :
 |_START |_1_|_|-> |_ab_|_|-> |_dca_|_|-> |_1_|_|->[NULL]
 Not Palindrome*/

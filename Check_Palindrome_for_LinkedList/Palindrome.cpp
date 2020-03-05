#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
};
Node *start;

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
bool palindrome(string str)
{
    string strc=str;
    reverse(str.begin(),str.end());

    if(str==strc)
        return true;
    return false;
}

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

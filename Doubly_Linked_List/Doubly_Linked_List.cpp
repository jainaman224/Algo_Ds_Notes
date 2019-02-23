#include<iostream>
using namespace std;
class node{
private:
    int data;
    node *next;
    node *prev;
public:
    node(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
 friend class Linked_List;
};
class Linked_List
{
private:
    node *head;
public:
    Linked_List()
    {
        head=NULL;
    }
void insertatbeg(int d)
    {
        node *n=new node(d);
        n->next=head;
        n->prev=NULL;
        head=n;

    }
void insertatend(int d)
{
    node *t=head;
    node *n=new node(d);
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=n;
    n->prev=t;

}
void insertatK(int d,int k)
{
    node *n=new node(d);
    node *t=head;
    node *temp=NULL;
    int cnt=1;
    while(head==NULL ||  k==1)
    {
        insertatbeg(d);
        return;
    }
    while(t->next!=NULL &&  cnt<k)
    {
        temp=t;
        t=t->next;
        cnt++;
    }
    n->prev=temp;
    n->next=temp->next;
    temp->next=n;
    t->prev=n;
}
    void print()
    {
        node *t=head;
        while(t!=NULL)
        {
            cout<<t->data<<" ->";
            t=t->next;

        }
        cout<<endl;

    }
    void delatbeg()
{
    if(head==NULL)
    {
        cout<<"no nodes left"<<endl;
        return;
    }
    node*t=head;
    head=t->next;
    head->prev=NULL;
    t->next=NULL;
    delete t;
}
void delatend()
{
    node *t=head;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->prev->next=NULL;
    delete t;
}
void delatK(int k)
{
    int cnt=1;
    node *t=head;
    node*temp=NULL;
    node *temp2=NULL;
    while(t->next!=NULL && cnt<k-1)
    {
        t=t->next;
        cnt++;
    }
    temp=t->next;
    t->next=temp->next;
    temp->next->prev=t;
    temp->next=NULL;
    delete temp;


}

};
int main()
{
    Linked_List ll;
    int d,c;
    char choice;
    ll.insertatbeg(1);
    ll.insertatbeg(2);
    ll.print();
    ll.insertatend(3);
    ll.print();
    ll.insertatK(4,3);
    ll.print();
    //ll.delatbeg();
    //ll.print();
    //ll.delatend();
    //ll.print();
    ll.delatK(2);
    ll.print();
   // ll.delatK(3);
    //ll.print();
}

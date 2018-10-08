#include<iostream>
using namespace std;
class node{
private:
    int data;
    node *next;
public:
    node(int d)
    {
        data=d;
        next=NULL;

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
      node*ptr=head;
      if(head==NULL)
      {
          head=n;
          n->next=head;
      }
      else
      {while(ptr->next!=head)
      {
          ptr=ptr->next;
      }
      n->next=head;
      ptr->next=n;
      head=n;
      }
 }
void insertatend(int d)
{
    node *t=head;
    node *n=new node(d);
    while(t->next!=head)
    {
        t=t->next;
    }
    t->next=n;
    n->next=head;


}
void insertatK(int d,int k)
{
    node *n=new node(d);
    node *t=head;
    int cnt=1;
    while(head==NULL ||  k==1)
    {
        insertatbeg(d);
        return;
    }
    while(t->next!=NULL &&  cnt<k-1)
    {

        t=t->next;
        cnt++;
    }
    n->next=t->next;
    t->next=n;
}


   void print()
    {
        node *t=head;
        do
        {
            cout<<t->data<<" ->";
            t=t->next;

        }while(t!=head);
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
    node *ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    ptr->next=head->next;
    head=head->next;
    t->next=NULL;
    delete t;
}
void delatend()
{
    node *t=head;
    node *temp=NULL;
    while(t->next!=head)
    {
        temp=t;
        t=t->next;
    }
    temp->next=head;
    t->next=NULL;
    delete t;
}
void delatK(int k)
{
    int cnt=1;
    node *t=head;
    node *temp=NULL;
    while(t->next!=NULL && cnt<k)
    {
        temp=t;
        t=t->next;
        cnt++;
    }
    temp->next=t->next;
    delete t;


}
};
 int main()
{
    Linked_List ll;
    int d,c;
    char choice;
    ll.insertatbeg(1);
    ll.insertatbeg(2);
    ll.insertatbeg(3);
    ll.print();
    ll.insertatend(4);
    ll.print();
    ll.insertatK(2,3);
    ll.print();
    ll.delatbeg();
    ll.print();
    ll.delatend();
    ll.print();
    ll.delatK(2);
    ll.print();
}

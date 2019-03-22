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
      node*ptr=head;
      if(head==NULL)
      {
          head=n;
          n->next=head;
          n->prev=n;
      }
      else
      {
            head->prev->next=n;
            n->prev=head->prev;
            n->next=head;
            head->prev=n;
            head=n;

      }


 }
 void insertatend(int d)
{
    node *n=new node(d);
    head->prev->next=n;
    n->prev=head->prev;
    n->next=head;


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
void delatbeg()
{
    node *t=head;
    head->prev->next=head->next;
    head->next->prev=head->prev;
    head=head->next;
    t->next=NULL;
    delete t;
}
void delatend()
{
    node *t;
    t=head->prev;
    t->prev->next=head;
    head->prev=t->prev;
    t->next=NULL;
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
   // ll.insertatK(10,3);
    //ll.print();
    ll.delatend();
    ll.print();
    ll.delatend();
    ll.print();
   // ll.delatend();
    //ll.print();
}

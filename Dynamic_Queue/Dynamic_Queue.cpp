//Queue
#include<iostream>

using namespace std;

struct Node{
    int info;
    Node *link;
};

void Enqueue(int data,Node**,Node**);
void Dequeue(Node**,Node**);
void Display(Node*,Node*);

int main()
{
    Node *First,*Last;
    First=NULL;
    Last=NULL;
    int data;
    int ch;
    do{
        cout<<"\n\tMENU";
        cout<<"\n1.Enqueue";
        cout<<"\n2.Dequeue";
        cout<<"\n3.Display";
        cout<<"\n4.Exit";
        cout<<"\nEnter choice...";
        cin>>ch;
        switch(ch)
        {
        case 1: cout<<"\nEnter new data:";
                cin>>data;
                Enqueue(data,&First,&Last);

                break;
        case 2: Dequeue(&First,&Last);
                break;
        case 3:Display(First,Last);
                break;

        }

    }while(ch>=1&&ch<=3);


    return 0;

}

void Enqueue(int data,Node **F,Node **L)
{
    Node *temp=new Node;
    temp->info=data;
    if(*L == NULL)
    {
        temp->link=NULL;
        *F=temp;
    }
    else
        temp->link=*L;
    (*L)=temp;

}

void Dequeue(Node **F,Node **L)
{
    if(*F == NULL)
    {
        cout<<"\nUnderflow...";
        return;
    }
    else if(*F == *L)
    {
        *F=NULL;
        *L=NULL;
        return;
    }
    Node *temp=NULL;
    temp=*L;
    while(temp->link != (*F))
    {
        temp=temp->link;
    }
    temp->link=NULL;
    *F=temp;

}
void Display(Node *F,Node *L)
{
    Node *temp=NULL;
    if(L == NULL)
   {
        cout<<"\nUnderflow";
        return ;
   }
    temp=L;
    while(temp->link != NULL)
    {
        cout<<temp->info<<"->";
        temp=temp->link;
    }
    cout<<temp->info<<"->!!!";
}

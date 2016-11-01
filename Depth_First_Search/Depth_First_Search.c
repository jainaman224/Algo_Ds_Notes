#include <stdio.h>
#include <stdlib.h>

//Structure for each vertex in graph
struct node
{
    int data;
    struct node* next;
};

//Function to add node at the end of given root
struct node* insert(struct node *root,int d)
{
    struct node *newPtr = (struct node*)malloc(sizeof(struct node));
    newPtr->data = d;
    newPtr->next = NULL;

    root->next = newPtr;

    return newPtr;
}

//Function to perform DFS
void explore(int node,int vis[],struct node start[])
{
    printf("%d ",node);
    vis[node]=1;

    struct node *ptr = start[node].next;

    for(;ptr!=NULL;ptr=ptr->next)
    {
        if(vis[ptr->data]==0)
        {
            explore(ptr->data,vis,start);
        }
    }
}


int main()
{
    int no_of_vertices = 7,i,vis[8];

    struct node start[8];

    for(i=1;i<=no_of_vertices;i++)
    {
        start[i].data=i;
        start[i].next=NULL;
        vis[i]=0;
    }

    /*
    Creates the following graph :
                 1
               /   \
              2     3
             / \   / \
            4   5 6   7
    */
    struct node *cur;
    cur = insert(&start[1],2);
    insert(cur,3);
    cur = insert(&start[2],4);
    insert(cur,5);
    cur = insert(&start[3],6);
    insert(cur,7);

    //The loop takes care of non connected graph also
    printf("DFS of the graph : \n");
    for(i=1;i<=7;i++)
    {
        if(vis[i]==0)
            explore(i,vis,start);
    }

    return 0;


    // Output : 1 2 4 5 3 6 7
}

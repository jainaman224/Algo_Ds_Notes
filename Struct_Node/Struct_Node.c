// C program which uses struct node to implement linked list


#include <stdio.h>

struct Node
{

    int number;

    struct Node *next;

};

int main()
{

  	struct Node* head = NULL;

        struct Node* second = NULL;

	struct Node* third = NULL;

        struct Node* fourth = NULL;

        struct Node* fifth = NULL;



    //five blocks have been allocated memory dynamically

        head = (struct Node*)malloc(sizeof(struct Node));

        second = (struct Node*)malloc(sizeof(struct Node));

        third = (struct Node*)malloc(sizeof(struct Node));

        fourth = (struct Node*)malloc(sizeof(struct Node));

        fifth = (struct Node*)malloc(sizeof(struct Node));



     head->number = 1; //assign data in first node

        head->next = second; //linking first and second node



	second->number = 2; //assign data in second node

        second->next = third; //linking second and third node



	third->number = 3; //assign data in third node

        third->next = fourth; //linking third and fourth node



	fourth->number = 4; //assign data in fourth node

        fourth->next = fifth; //linking fourth and fifth node



	fifth->number = 5; //assign data in fifth node

        fifth->next = NULL;



	return 0;

}


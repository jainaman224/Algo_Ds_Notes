#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
    node(int value): data(value), next(NULL) {}
} *head = NULL;

bool Is_List_Empty() {
    return (head == NULL);
}

void Insert_At_Beginning(int value) {
    node *temp = new node(value);
    temp -> next = head;
    head = temp;
}

void Insert_At_End(int value) {
    node *temp = new node(value);
    if(Is_List_Empty()) {
        head = temp;
        return;
    }
    node  *current = head;
    while(current -> next != NULL) {
        current = current -> next;
    }
    current -> next = temp;
}

void Insert_After_Value(int desired, int value) {

    node *current = head;
    while(current != NULL && current -> data != desired)
        current = current -> next;

    if(current == NULL) {
        cout << "Element " << desired << " is not in list" << endl;
    } else {
        node *temp = new node(value);
        temp -> next = current -> next;
        current -> next = temp;
    }
}

void Delete_At_Beginning() {
    if(Is_List_Empty())
        cout << "List is empty" << endl;
    else {
        node *temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
}

void Delete_At_End() {
    if(Is_List_Empty()) {
        cout << "List is empty" << endl;
        return;
    }

    if(head -> next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    node *temp = head;
    while(temp -> next -> next != NULL) {
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = NULL;
}

void Delete_With_Value(int desired) {
    if(Is_List_Empty()) {
        cout << "List is empty" << endl;
        return;
    }

    node *temp = head, *prev = NULL;
    if(head -> data == desired) {
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        return;
    }

    while(temp != NULL && temp -> data != desired) {
        prev = temp;
        temp = temp -> next;
    }
    if(temp == NULL) {
        cout << "Element " << desired << " not in list" << endl;
    } else {
        prev -> next = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
}

void Search(int desired) {
    node *temp = head;
    while(temp != NULL && temp -> data != desired) {
        temp = temp -> next;
    }
    if(temp == NULL) {
        cout << "Element " << desired << " not found" << endl;
    } else {
        cout << "Element " << desired << " is present in list" << endl;
    }
}

void Print_Linked_List() {
    if(Is_List_Empty()) {
        cout << "List is Empty" << endl;
        return;
    }

    node *current = head;
    while(current != NULL) {
        cout << current -> data;
        current = current -> next;
        if (current != NULL)
            cout << " -> ";
    }
    cout << endl;
}

void Length_Iterative() {
    int length = 0;
    node *temp = head;
    while (temp) {
        length += 1;
        temp = temp -> next;
    }
    cout << "Length is " << length << " (Iterative)" << endl;
}

int Recursive_Count(node* current) {
    if(current == NULL)
        return 0;
    return (1 + Recursive_Count(current -> next));
}

void Length_Recursive() {
    int length = Recursive_Count(head);
    cout << "Length is " << length << " (Recursive)" << endl;
}

int main() {
    for(int i = 0; i < 5; i++)
        Insert_At_Beginning(i);

    Print_Linked_List();

    for(int i = 5; i < 10; i++)
        Insert_At_End(i);

    Print_Linked_List();

    Insert_After_Value(5, 9);
    Insert_After_Value(10, 9);

    Print_Linked_List();

    for(int i = 0; i < 3; i++)
        Delete_At_End();

    Print_Linked_List();

    for(int i = 0; i < 3; i++)
        Delete_At_Beginning();

    Print_Linked_List();

    Delete_With_Value(1);
    Delete_With_Value(5);

    Print_Linked_List();

    Search(6);
    Search(8);

    Length_Iterative();
    Length_Recursive();

    return 0;
}

/*  Output
    4 -> 3 -> 2 -> 1 -> 0
    4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 6 -> 7 -> 8 -> 9
    Element 10 is not in list
    4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 9 -> 6 -> 7 -> 8 -> 9
    4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 9 -> 6
    1 -> 0 -> 5 -> 9 -> 6
    0 -> 9 -> 6
    Element 6 is present in list
    Element 8 not found
    Length is 3 (Iterative)
    Length is 3 (Recursive)
*/

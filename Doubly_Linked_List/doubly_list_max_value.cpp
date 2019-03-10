#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
	node *prev;
	
};
// class implementing doubly linked list functions 
class linked_list{
	private:
		node *head;
	public:
		linked_list(){
			head = NULL;
		}
	// function for insertion of node at the last of doubly linked list 
	void insert_last(int n){
	    node *new_node = new node;
	    new_node->data = n;
	    new_node->next = NULL;
	    if(head == NULL){
	        new_node->prev = NULL;
	        head  = new_node;
	        return;
	    }
	    node *ptr = head;
	    while(ptr->next != NULL){
	        ptr = ptr->next;
	    }
	    ptr->next = new_node;
	    new_node->prev = ptr;
	}
	// function for display of doubly linked list
	void display(){
	    node *ptr = head;
	    while(ptr != NULL){
	        cout << ptr->data << " ";
	        ptr = ptr->next;
	    }
	    cout << endl;
	}
	// function for maximum value from the whole list 
	void max_value(){
	    node *ptr = head;  // taking a reference to head 
	    int max = ptr->data;  // setting first value as the maximum value 
	    while(ptr != NULL){
	        if(ptr->data > max){  // check whether any of the value is greater than the previous set value while transversing the whole list 
	            max = ptr->data;   // if found then update the max value to the new value 
	       }
	        ptr = ptr->next;   // incrementing the ptr 
	        
	    }
	    cout << "max value is " << max;   // printing the max value 
	}
};		
// driver main function for testing out other functions 
int main(){
	linked_list l;
	l.insert_last(34);
	l.insert_last(2);
	l.insert_last(78);
	l.insert_last(18);
	l.insert_last(120);
	l.insert_last(39);
	l.insert_last(7);
	l.display();  // 34 2 78 18 120 39 7 
	l.max_value(); // 120
	
}

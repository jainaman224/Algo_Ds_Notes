//this is a code for generic Queue
//you can use any kind of item with this Queue - int,char,double etc

#include <iostream>
#include <vector>
using namespace std;

//here is the generic stack class to hold the item of any kind(acceptable to c++ stl vector)

template <class T>
class Stack
{
	vector<T> data;
public:
	void push(T);
	void pop();
	T top();
	bool isEmpty(){
		return data.empty();
	}
};

template <class T>
void Stack<T>::push (T item) 
{
	data.push_back(item);
}

template <class T>
void Stack<T>::pop () 
{
	if (data.empty()) { 
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	data.pop_back();
}

template <class T>
T Stack<T>::top ()
{
	if (data.empty()) { 
		throw out_of_range("Stack<>::top(): empty stack");
	}
	return data.back();
}

//now goes the Queue class using the above stack class

//we'll need two stacks - 
//		stack 1
//		stack 2
//and we've to choose which one of the operations enQueue and deQueue to make costly
//here I've made deQueue costly
template <class T>
class Queue
{
	Stack<T> S1,S2;
public:
	void enQueue(T);
	T deQueue();
	T peek();
	bool isEmpty(){
		return (S1.isEmpty() && S2.isEmpty());
	}
};

template <class T>
T Queue<T>::peek()
{
	if(S1.isEmpty() && S2.isEmpty())
		throw out_of_range("Queue<>::peek(): empty Queue");
	else if(!S2.isEmpty())
	{
		return S2.top();
	}
	else
	{
		T xItem;
		while(!S1.isEmpty())
		{
			xItem = S1.top();
			S1.pop();
			S2.push(xItem);
		}
		return S2.top();
	}
}

template <class T>
void Queue<T>::enQueue(T item)
{
	//push the new item to Stack1 (assuming unlimited memory)
	S1.push(item);
}

template <class T>
T Queue<T>::deQueue()
{
	if(S1.isEmpty() && S2.isEmpty())
		throw out_of_range("Queue<>::deQueue(): empty Queue");
	else if(!S2.isEmpty())
	{
		T xItem = S2.top();
		S2.pop();
		return xItem;
	}
	else if(!S1.isEmpty())
	{
		T xItem;
		while(!S1.isEmpty())
		{
			xItem = S1.top();
			S1.pop();
			S2.push(xItem);
		}
		S2.pop();
		return xItem;
	}
}

//for testing purposes

void checkStack(){
	cout<<endl<<"Initiating Stack test : "<<endl;
	Stack<double> S;
	cout<<"inserted 3.56"<<endl;
	S.push(3.56);
	cout<<"inserted 4.67"<<endl;
	S.push(4.67);
	cout<<"inserted 45.90"<<endl;
	S.push(45.90);
	cout<<"Topmost element : "<<S.top()<<endl;
	cout<<"Popped 2 elements."<<endl;
	S.pop();
	S.pop();
	cout<<"Topmost element : "<<S.top()<<endl;
}

void checkQueue(){
	cout<<endl<<"Initiating Queue test : "<<endl;
	Queue<char> Q;
	cout<<"Inserted text QUEUE."<<endl<<"checking..."<<endl;
	Q.enQueue('Q');
	Q.enQueue('U');
	Q.enQueue('E');
	Q.enQueue('U');
	Q.enQueue('E');
	cout<<"This is a ";
	while(!Q.isEmpty()){
		cout<<Q.deQueue();
	}
	cout<<endl;
}

int main()
{
	//for testing purpose only
	checkStack();
	checkQueue();
	return 0;
}

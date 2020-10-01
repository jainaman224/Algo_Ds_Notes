#include <iostream>

using namespace std;

class stack
{
    int *array;
    int tos;
    int size;

public:
    stack()
    {
        size = 10;
        array = new int[size];
        tos = -1;
    }

    stack(int size)
    {
        this -> size = size;
        array = new int[size];
        tos = -1;
    }

    void push(int value)
    {
        if(tos == size - 1)
            cout << "Stack is full" << endl;
        else
            array[++tos] = value;
    }

    void pop()
    {
        if(tos == -1)
            cout << "Stack is empty" << endl;
        else
            --tos;
    }

    void traverse()
    {
        int temp = tos - 1;

        if(tos == -1)
            cout << "Stack is empty" << endl;
        else
        {
            cout << "Top of stack is : " << array[tos] << endl;

            if(temp > -1)
                cout << "Other : ";

            while(temp > -1)
                cout << array[temp--] << " ";

            cout << endl;
        }
    }
};

int main()
{
    stack st(20);
    int x = 0;
    cout << "Enter the choice number\n";
    cout << "1.Push\n2.Pop\n3.Traverse\n4.Exit";
    cin >> x;
    while(x != 4){
        switch(x){
            case 1:
                int temp;
                cout << "Enter element to push\n';
                cin >> temp;
                s.push(temp);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.traverse();
                break;
            default:
                cout << "Enter 1 to push\nEnter 2 to pop\nEnter 3 to traverse\nEnter 4 to exit\n";
        }
    }
return 0;
}

/* Output

    Stack is full
    Top of stack is : 4
    Other : 3 2 1 0
    Stack is empty

*/

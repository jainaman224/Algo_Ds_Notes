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
    stack st(5);

    for(int i = 0; i < 6; i++)
    {
        st.push(i);
    }

    st.traverse();

    for(int i = 0; i < 6; i++)
    {
        st.pop();
    }

    return 0;
}

/* Output

    Stack is full
    Top of stack is : 4
    Other : 3 2 1 0
    Stack is empty

*/

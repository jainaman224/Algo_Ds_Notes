class Stacks
{
    private int[] array;
    private int tos;
    private int size;

    public Stacks()
    {
        size = 10;
        array = new int[size];
        tos = -1;
    }

    public Stacks(int size)
    {
        this.size = size;
        array = new int[size];
        tos = -1;
    }

    public void push(int value)
    {
        if(tos == size - 1)
            System.out.println("Stack is full");
        else
            array[++tos] = value;
    }

    public void pop()
    {
        if(tos == -1)
            System.out.println("Stack is empty");
        else
            --tos;
    }

    public void traverse()
    {
        int temp = tos - 1;

        if(tos == -1)
            System.out.println("Stack is empty");
        else
        {
            System.out.println("Top of stack is : " + array[tos]);

            if(temp > -1)
                System.out.print("Other : ");

            while(temp > -1)
                System.out.print(array[temp--] + " ");

            System.out.println();
        }
    }

    public static void main(String[] args)
    {
        Stacks st = new Stacks(5);

        for(int i = 0; i < 6; i++)
        {
            st.push(i);
        }

        st.traverse();

        for(int i = 0; i < 6; i++)
        {
            st.pop();
        }
    }
}

/* Output

    Stack is full
    Top of stack is : 4
    3 2 1 0
    Stack is empty

*/

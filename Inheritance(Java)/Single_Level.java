class Rectangle
{
    float length;
    float breadth;

    Rectangle()
    {
        length = 5;
        breadth = 6;
    }
}

class Area extends Rectangle
{
    public float calculate()
    {
        return length * breadth;
    }
}

class Single_Level
{
    public static void main(String args[])
    {
        Area a = new Area();

        System.out.println("Area = " + a.calculate() + " square meters");
    }
}

/* Output

Area = 30 square meters

*/

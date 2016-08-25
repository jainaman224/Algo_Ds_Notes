class Father
{
    int age;

    public void setage()
    {
        age = 75;
    }

    public int getage()
    {
        return age;
    }
}

class Son extends Father
{
    int S_age;

    public void setage_S()
    {
        S_age = 45;
    }

    public int getage_S()
    {
        return S_age;
    }
}

class GrandSon extends Son
{
    int GS_age;

    public void setage_GS()
    {
        GS_age = 15;
    }

    public int getage_GS()
    {
        return GS_age;
    }
}

class Multi_Level
{
    public static void main(String args[])
    {
        GrandSon obj = new GrandSon();

        obj.setage();
    	obj.setage_S();
    	obj.setage_GS();

        System.out.println("Father's age : " + obj.getage());
        System.out.println("Son's age : " + obj.getage_S());
    	System.out.println("Grandson's age : " + obj.getage_GS());
    }
}

/* Output

Father's age : 75
Son's age : 45
Grandson's age : 15

*/

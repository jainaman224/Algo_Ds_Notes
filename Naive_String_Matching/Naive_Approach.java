class Main
{
    public static void search(String text, String pattern)
    {
        int lengthText = text.length();
        int lengthPattern = pattern.length();

        for(int i = 0; i <= lengthText - lengthPattern; i++)
        {
            int j;

            for(j = 0; j < lengthPattern; j++)
                if(text.charAt(i + j) != pattern.charAt(j))
                    break;

            if(j == lengthPattern)
               System.out.println("Pattern found at " + (i + 1));
        }
    }

    public static void main(String[] args)
    {
       String text = "namanchamanbomanamansanam";
       String pattern = "aman";
       search(text, pattern);
    }
}

/* Output

Pattern found at 2
Pattern found at 8
Pattern found at 17

*/

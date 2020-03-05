class MethodOverloading {

    // this method accepts int
    private static void display(int a){
        System.out.println("Got Integer data.");
    }

    // this method accepts String object
    private static void display(String a){
        System.out.println("Got String object.");
    }
    //this method accepts float value
     private static void display(float a){
        System.out.println("Got Float data.");
    }
    //this method accepts three integer value
     private static void display(int a,int b,int c){
        System.out.println("Got Three Integer data.");
    }

    public static void main(String[] args) {
        display(1);
        display("Hello");
        display(2.0);
        display(4,5,6);
    }
}

/*
Sample output
Got Integer data.
Got String object.
Got Float data.
Got Three Integer data.
*/

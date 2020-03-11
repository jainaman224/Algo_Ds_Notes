rgsoc class rgsoc{

    public static void display(int[] arr) {
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }



    public static void swap(int[] arr,int left,int right) {
        int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++; right--;
    }
    public static void reverse(int[] arr,int left , int right){
           while(left<right){
                swap(arr,left,right);
           }
    }
   private static void rotate(int[] arr,int r){
        reverse(arr,arr.length-r,arr.length-1);
        reverse(arr,0,arr.length-r-1);
        reverse(arr,0,arr.length-1);
    }


    public static void main(String[] args) {
       scanner scn=new Scanner(System.in);
       int x=scn.nextInt();
       int[] arr==new int [x];
        for(int i=0;i<arr.length;i++){
            arr[i]=scn.nextInt();
        }
        System.out.print("array before rotation");
       display(arr);
       System.out.print("enter the value by which we want to rotate");
       
       int n=scn.nextInt();
         rotate(arr,n);
         display(arr);
       
    }


}
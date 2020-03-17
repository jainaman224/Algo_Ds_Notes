mport java.util.*;
class arrayrot{
       static Scanner scn=new Scanner(System.in);
   
   
    public static void input(int[] arr){
        for(int i=0;i<arr.length;i++){
        arr[i]=scn.nextInt();
        
        }
    }
      
      
public static void reverse(int[] arr, int left,int right){
    //    int left=0;
    //   int right=arr.length-1;
        while(left<=right){
            int temp =arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;right--;
        }    
        
        // System.out.println();
   }

   public static void rotate(int[] arr,int r){
      if(r<0){
         r=(r%arr.length+arr.length);
      }else{
         r%=arr.length;
      }

      
   reverse(arr,arr.length-r,arr.length-1);
   reverse(arr,0,arr.length-r-1);
   reverse(arr,0,arr.length-1);
   }
   public static void main(String[] args){
    //    Scanner scn=new Scanner(System.in);
       int size=scn.nextInt();
    //    int arr[]={1,2,3,4,5,6,7,8};
       int[] arr = new int[size];
       System.out.print("elements");
    //    System.out.println();
       input(arr);
    //    reverse(arr,0,size-1);
       System.out.print("enter the index for rotation");
       int index=scn.nextInt();
       rotate(arr,index);
       for(int i =0 ; i<=arr.length-1;i++)
    System.out.print(arr[i]);
   }
}




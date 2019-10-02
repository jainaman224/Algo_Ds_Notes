import java.util.Scanner;

public class spiralprint {
	public static int[][] takeinput(){
		Scanner s=new Scanner(System.in);
		int row=s.nextInt();
		int col=s.nextInt();
		int[][] arr=new int[row][col];
		for(int i=0;i<arr.length;i++) {
			for (int j=0;j<arr[i].length;j++) {
				arr[i][j]=s.nextInt();
			}
		}
		return arr;
	}
	
	public static void spiral(int[][] arr) {
int count=0;
		int rowstart=0;
int rowend=arr.length-1;
int colstart=0;
int colend=arr[0].length-1;
int n=arr.length*arr[0].length;
	while(count<n) {
for(int j=colstart;count<n && j<=colend;j++) {//multiple checking of count is used because count is only checked after one iteration of while loop but we are incrementing count in every for llop which are part of one iteration of while loop
			System.out.print(arr[rowstart][j]+" ");
		count++;
		}
		rowstart++;
		for(int i=rowstart;count<n && i<=rowend;i++) {
			System.out.print(arr[i][colend]+" ");
		count++;
		}
		colend--;
	for(int j=colend;count<n && j>=colstart;j--) {
		System.out.print(arr[rowend][j]+" ");
	count++;
	}
	rowend--;
	for(int i=rowend;count<n && i>=rowstart;i--) {
		System.out.print(arr[i][colstart]+" ");
	count++;
	}
	colstart++;
	}
}
	public static void main(String[] arg) {
		int[][] arr=takeinput();
	spiral(arr);
	}

}

# Bead Sort Algorithm 
It also known as Gravity sort, this algorithm was inspired from natural phenomenons and was designed keeping in mind objects(or beads) falling under the influence of gravity.

When one tries to visualize this algorithm it appears as if beads are falling down under the influence of gravity to the bottom-most level they can reach resulting the set of beads being arranged in a descending order from the ground up.

Lets say that we have to sort the numbers 3, 4, 1, 2. The above algorithm would work like this.

![Bead_sort_2](https://user-images.githubusercontent.com/55893326/78024003-46896a00-7375-11ea-807e-d7838158ad90.jpg)

**Positive numbers are represented by a set of beads like those on an abacus.
## Bead-Sort Algorithm
The bead sort operation can be compared to the manner in which beads slide on parallel poles, such as on an abacus. However, each pole may have a distinct number of beads. Initially, it may be helpful to imagine the beads suspended on vertical poles. In Step 1, such an arrangement is displayed using n=5 rows of beads on m=4 vertical poles. The numbers to the right of each row indicate the number that the row in question represents; rows 1 and 2 are representing the positive integer 3 (because they each contain three beads) while the top row represents the positive integer 2 (as it only contains two beads).

If we then allow the beads to fall, the rows now represent the same integers in sorted order. Row 1 contains the largest number in the set, while row n contains the smallest. If the above-mentioned convention of rows containing a series of beads on poles 1..k and leaving poles k+1..m empty has been followed, it will continue to be the case here.

The action of allowing the beads to "fall" in our physical example has allowed the larger values from the higher rows to propagate to the lower rows. If the value represented by row a is smaller than the value contained in row a+1, some of the beads from row a+1 will fall into row a; this is certain to happen, as row a does not contain beads in those positions to stop the beads from row a+1 from falling.

The mechanism underlying bead sort is similar to that behind counting sort; the number of beads on each pole corresponds to the number of elements with value equal or greater than the index of that pole.
## Implementation
This implementation is written in Python; it is assumed that the input_list will be a sequence of integers. The function returns a new list rather than mutating the one passed in, but it can be trivially modified to operate in place efficiently.
```javascript
def beadsort(input_list):
    """Bead sort."""
    return_list = []
    # Initialize a 'transposed list' to contain as many     elements as
    # the maximum value of the input -- in effect, taking the   'tallest'
    # column of input beads and laying it out flat
    transposed_list = [0] * max(input_list)
    for num in input_list:
        # For each element (each 'column of beads') of the input list,
        # 'lay the beads flat' by incrementing as many elements of the
        # transposed list as the column is tall.
        # These will accumulate atop previous additions.
        transposed_list[:num] = [n + 1 for n in transposed_list[:num]]
    # We've now dropped the beads. To de-transpose, we count the
    # 'bottommost row' of dropped beads, then mimic removing this
    # row by subtracting 1 from each 'column' of the transposed list.
    # When a column does not reach high enough for the current row,
    # its value in transposed_list will be <= 0.
    for _ in input_list:
        # Counting values > 0 is how we tell how many beads are in the
        # current 'bottommost row'. Note that Python's bools can be
        # evaluated as integers; True == 1 and False == 0.
        return_list.append(sum(n > 0 for n in transposed_list))
        # Remove the 'bottommost row' by subtracting 1 from each element.
        transposed_list = [n - 1 for n in transposed_list]
    # The resulting list is sorted in descending order
    return return_list
```
## EXAMPLE OF BEAD SORT
Program written in JAVA
```
public class BeadSort 
{
	public static void main(String[] args)
	{
		BeadSort now=new BeadSort();
		int[] arr=new int[(int)(Math.random()*11)+5];
		for(int i=0;i<arr.length;i++)
			arr[i]=(int)(Math.random()*10);
		System.out.print("Unsorted: ");
		now.display1D(arr);
		int[] sort=now.beadSort(arr);
		System.out.print("Sorted: ");
		now.display1D(sort);
	}
	int[] beadSort(int[] arr)
	{
		int max=a[0];
		for(int i=1;i<arr.length;i++)
			if(arr[i]>max)
				max=arr[i];
		//Set up abacus
		char[][] grid=new char[arr.length][max];
		int[] levelcount=new int[max];
		for(int i=0;i<max;i++)
		{
			levelcount[i]=0;
			for(int j=0;j<arr.length;j++)
				grid[j][i]='_';
		}
		//Drop the beads
		for(int i=0;i<arr.length;i++)
		{
			int num=arr[i];
			for(int j=0;num>0;j++)
			{
				grid[levelcount[j]++][j]='*';
				num--;
			}
		}
		System.out.println();
		display2D(grid);
		//Count the beads
		int[] sorted=new int[arr.length];
		for(int i=0;i<arr.length;i++)
		{
			int putt=0;
			for(int j=0;j<max&&grid[arr.length-1-i][j]=='*';j++)
				putt++;
			sorted[i]=putt;
		}
		return sorted;
	}
	void display1D(int[] arr)
	{
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
	void display1D(char[] arr)
	{
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
	void display2D(char[][] arr)
	{
		for(int i=0;i<arr.length;i++)
			display1D(arr[i]);
		System.out.println();
	}
}
```
## COMPLEXITY OF BEAD SORT ALGORITHM
Bead sort can be implemented with four general levels of complexity, among others:

**O(1)**: The beads are all moved simultaneously in the same time unit, as would be the case with the simple physical example above. This is an abstract complexity, and cannot be implemented in practice.

**O((n)^1/2)**: In a realistic physical model that uses gravity, the time it takes to let the beads fall is proportional to the square root of the maximum height, which is proportional to n.

**O(n)**: The beads are moved one row at a time. This is the case used in the analog and digital hardware solutions.

**O(S)**, where S is the sum of the integers in the input set: Each bead is moved individually. This is the case when bead sort is implemented without a mechanism to assist in finding empty spaces below the beads, such as in software implementations.

**Space Complexity:** Bead sort is the record-holder as for waste. The costs for the extra memory exceed the costs for storing the array itself. Its memory complexity is O(n^2)
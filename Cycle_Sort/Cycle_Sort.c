//Cycle Sort in C
#include<stdio.h>

void sort(int a[], int n)
{
    int writes = 0,start,element,pos,temp,i;
    
    // Find position where we put the element.
    for (start = 0; start <= n - 2; start++) {
        element = a[start];
        pos = start;
        for (i = start + 1; i < n; i++)
            if (a[i] < element)
                pos++;
        
        // If element is already in correct position
        if (pos == start)
            continue;
        while (element == a[pos])
            pos += 1;
        
        // put the element to it's right position
        if (pos != start) {
            temp = element;
            element = a[pos];
            a[pos] = temp;
            writes++;
        }
        
        // Rotate rest of the cycle
        while (pos != start) {
            pos = start;
            for (i = start + 1; i < n; i++)
                if (a[i] < element)
                    pos += 1;
            while (element == a[pos])
                pos += 1;
            
            // put the element to it's right position
            if (element != a[pos]) {
                temp = element;
                element = a[pos];
                a[pos] = temp;
                writes++;
            }
        }
    }
}

int main()
{
    int a[50], size;
    printf("Enter number of elements/n");
    scanf("%d",&size);
    printf("Enter array elements: \n");
    for(int i=0;i<size;i++)
    {
        printf("a[%d] :",i);
        scanf("%d",&a[i]);
    }
  
    sort(a, size);
    printf("After sort, array : \n");
    for (int i = 0; i < size; i++)
        printf("%d ",a[i]);
    return 0;
}
/*Output-
Enter number of elements/n6
Enter array elements:
a[0] :3
a[1] :9
a[2] :1
a[3] :-6
a[4] :4
a[5] :8
After sort, array :
-6 1 3 4 8 9*/

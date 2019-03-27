#include<stdio.h>
#include<iostream>
using namespace std;
void sort(int a[], int n)  
{  
    int writes = 0,start,element,pos,temp,i;
    for (start = 0; start <= n - 2; start++) {  
        element = a[start];  
        pos = start;  
        for (i = start + 1; i < n; i++)  
            if (a[i] < element)  
                pos++;  
        if (pos == start)  
            continue;  
        while (element == a[pos])  
            pos += 1;  
        if (pos != start) {    
        temp = element;  
        element = a[pos];  
            a[pos] = temp;    
            writes++;  
        }  
        while (pos != start) {  
            pos = start;  
            for (i = start + 1; i < n; i++)  
                if (a[i] < element)  
                    pos += 1;  
            while (element == a[pos])  
                pos += 1;  
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
    cout<<"Enter number of elemnts"<<endl;
    cin>>size;
    cout<<"Enter array elements: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<"a["<<i<<"] :"<<endl;
        cin>>a[i];
    }
  
    sort(a, size);  
    cout<<"After sort, array : "<<endl;  
    for (int i = 0; i < size; i++)  
        cout<<a[i]<<" ";  
    return 0;  
} 

// output:
Enter number of elemnts                                                                                                 
8                                                                                                                       
Enter array elements:                                                                                                   
a[0] :12                                                                                                                
a[1] :2                                                                                                                 
a[2] :1                                                                                                                 
a[3] :9                                                                                                                 
a[4] :-4                                                                                                                
a[5] :2                                                                                                                 
a[6] :4                                                                                                                 
a[7] :4                                                                                                                 
After sort, array :                                                                                                     
-4 1 2 2 4 4 9 12 
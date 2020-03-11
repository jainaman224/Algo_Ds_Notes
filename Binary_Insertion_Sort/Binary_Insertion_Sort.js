//Binary Insertion sort is a variant of Insertion sorting in which proper location to insert
//the selected element is found using the binary search.
var i=0;
//taking the size of the array dynamically
var n=prompt("enter the size of your array");
var arr = [];
for(var i=0; i<n; i++)
{
    //Taking Input from user
    arr[i] = prompt('Enter Element ' + (i+1));
}

function binarysearch(array,item,start,end)
{
    if(end <= start)
        return (item > array[start])? (start+1): start;
    var mid = (start+end)/2;
    if(item == array[mid])
        return mid+1;
    if(item >array[mid])
        return binarysearch(array,item,mid+1,end);
    return binarysearch(array,item,start,mid-1);
}

function insertionsort(array,size)
{
    var i,location,j,k,key;
    for(i=1;i<size;++i)
    {
        j = i-1;
        key = arr[i];
        //to find location where key sould be inserted
        location = binarysearch(arr,key,0,j);
         // to move all elements after location to create space for key
        while(j >= location)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

insertionsort(arr,n);
console.log(arr);

//INPUT:Enter the size of the array 5
//Enter the elements
//34
//75
//24
//1
//6
//OUTPUT: 1 6 24 34 75

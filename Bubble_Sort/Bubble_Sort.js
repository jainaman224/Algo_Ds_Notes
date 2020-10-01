function Bubble_Sort(array)
{
    var temp;

    for (var i = 0; i < array.length; i++)
    {
        for (var j = 0; j < array.length - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


array = [2, 4, 3, 1, 6, 8, 4];

Bubble_Sort(array);
console.log(array);


/* Output

[ 1, 2, 3, 4, 4, 6, 8 ]

*/

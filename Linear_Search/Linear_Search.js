function linearSearch(array, searchItem)
{
	for (i = 0; i < array.length; i++) {
		if(array[i] === searchItem)
		{
			console.log('Item found at position ' + (i+1));
			return;
		}
	}
	console.log('Item not found');
}

var array = [12, 34, 23, 5, 100];

linearSearch(array, 5);
linearSearch(array, 95);
linearSearch(array, 12);
linearSearch(array, 'simmi');


// output

// Item found at position 4
// Item not found
// Item found at position 1
// Item not found


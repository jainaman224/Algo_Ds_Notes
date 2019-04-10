function prefixSum(array) {
	const prefix_array = [];
	let sum = 0;
	for (const i in array) {
		sum = sum + array[i];
		prefix_array.push(sum);
	}
	return prefix_array;
}

const array = [3, 2, 4, 6, 7];
const prefix_array = prefixSum(array);
console.log(prefix_array);

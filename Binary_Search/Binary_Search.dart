String binarySearch(List<int> list, int x){
	int min = 0;
	int max = list.length - 1;
	while (min<=max){
		int mid = ((min+max) / 2).floor();
		if(x == list[mid]){
			return "Found 15 at Index $mid";
		}else if(x < list[mid]){
			max = mid - 1;
		}else{
			min = mid + 1;
		}
	}
	return "Not found !";
}

main(){
	List<int> list = [0, 2, 5, 8, 10, 12, 15, 30, 45];
	print(binarySearch(list, 15));
}

/*
Sample Output :
Found 15 at Index 6
*/

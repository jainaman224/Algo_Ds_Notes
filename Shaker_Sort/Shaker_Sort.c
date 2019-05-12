#include <stdio.h>
void shakerSort(int array[],int length) {
int isSwaped ;
int i;
do {
  /*variable for finding if any swaping happens sets to 0 (which means its false) first */
    isSwaped=0;
    /*first loop*/
    for ( i = length-1; i>=0 ; i--) {
      /* checks if any small number is caught  */
    if (array[i+1]<array[i]) {
      /* swap the digits */
      int temp;
      temp=array[i+1];
      array[i+1]=array[i];
      array[i]=temp;
      //sets the isSwaped to 1(true)
      isSwaped=1;
    }
  }
  /*loop in opposite direction to first one*/
  for ( i = 0; i < length; i++) {
    /* checks if any small number is caught  */
    if (array[i+1]<array[i]) {
      /* swap the digits */
      int temp;
      temp=array[i+1];
      array[i+1]=array[i];
      array[i]=temp;
      //sets the isSwaped to true
      isSwaped=1;
    }
}

} while(isSwaped);
/*do-while loops ends if there is no swaping*/


//prints sorted array
  printf("sorted array is ");
for ( i = 0; i<=length; i++) {
  /* prints every element of array*/
  printf("%i ",array[i]);
}

}
int main() {
  /* psuedo data for array */
  int numberOfElements=6;
  int arr[]={2,7,8,1,4,1};
  //call to shaker sort function
  shakerSort(arr,numberOfElements-1);
  return 0;
}

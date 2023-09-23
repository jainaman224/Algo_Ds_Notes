// Cycle sort is an in-place and unstable sorting algorithm, a comparison sort
// that is based on the idea that array to be sorted can be divided into cycles.

#include <stdio.h>

// Cycle Sort begins
void cyclesort(int a[], int n) {
  int write = 0, start, element, pos, temp, i;

  // Finding the position where we put the element.
  for (start = 0; start <= n - 2; start++) {
    element = a[start];
    pos = start;

    for (i = start + 1; i < n; i++)
      if (a[i] < element)
        pos++;

    // Checking if element is already in correct position
    if (pos == start)
      continue;

    while (element == a[pos])
      pos += 1;

    // Putting the element to their right position
    if (pos != start) {
      temp = element;
      element = a[pos];
      a[pos] = temp;
      write++;
    }

    // Rotating rest of the cycle
    while (pos != start) {
      pos = start;
      for (i = start + 1; i < n; i++)
        if (a[i] < element)
          pos += 1;

      while (element == a[pos])
        pos += 1;

      // Putting the element to their right position
      if (element != a[pos]) {
        temp = element;
        element = a[pos];
        a[pos] = temp;
        write++;
      }
    }
  }
}

int main() {
  int n, i;
  int a[20];
  printf("Enter the no. of elements : ");
  scanf("%d", &n);
  printf("Enter the elements : ");
  for (i = 0; i < n; i++)
    scanf("%d ", a[i]);
  cyclesort(a, n);
  printf("After sorting : ");
  for (i = 0; i < n; i++)
    printf("%d  ", a[i]);
  return 0;
}

/* Sample Output:

Enter the no. of elements : 4
Enter the elements : 5 8 2 3
After sorting : 2 3 5 8
*/

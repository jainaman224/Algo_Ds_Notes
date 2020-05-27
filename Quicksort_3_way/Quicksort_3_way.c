#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef void qsort3way_swap(void *a, void *b);
typedef int qsort3way_cmp(void const *a, void const *b);

static void qsort3way_aux(char *array_begin, char *array_end, size_t size,
                          qsort3way_cmp *cmp, qsort3way_swap *swap) {
  if (array_begin < array_end) {
    char *i = array_begin + size;
    char *lower = array_begin;
    char *greater = array_end;
      // 3-way partition based quick sort 
    while (i < greater) {
      int ret = cmp(lower, i);
      if (ret < 0) {
        swap(i, lower);
        i += size;
        lower += size;
      } else if (ret > 0) {
        greater -= size;
        swap(i, greater);
      } else {
        i += size;
      }
    }
      // Recur two halves
    qsort3way_aux(array_begin, lower, size, cmp, swap);
    qsort3way_aux(greater, array_end, size, cmp, swap);
  }
}

static void qsort3way(void *array_begin, void *array_end, size_t size,
                      qsort3way_cmp *cmp, qsort3way_swap *swap) {
  qsort3way_aux(array_begin, array_end, size, cmp, swap);
}
 // A utility function to perform swapping operations 
static void swap_int_aux(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

static void swap_int(void *a, void *b) { swap_int_aux(a, b); }

static int cmp_int_aux(int const *a, int const *b) {
  if (*a < *b) {
    return 1;
  } else if (*a > *b) {
    return -1;
  } else {
    return 0;
  }
}

static int cmp_int(void const *a, void const *b) { return cmp_int_aux(a, b); }

static void print_int(char const *intro, int const *array, size_t const size) {
  printf("%s:", intro);
  for (size_t i = 0; i < size; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");
}

#define SIZE 42

int main(void) {
  int array[SIZE];

  srand((unsigned int)time(NULL));
  for (size_t i = 0; i < SIZE; i++) {
    array[i] = rand() % SIZE - SIZE / 2;
  }

  print_int("before", array, SIZE);

  qsort3way(array, array + SIZE, sizeof *array, cmp_int, swap_int);

  print_int("after", array, SIZE);
}
// INPUT: 9 1 13 14 9 -17 -12 -7 -6 3 4 -2 -4 -3 -11 20 20 18 -13 -11 -8 -3 15 -19 2 -10 -14 17 3 -4 -4 -8 19 4 -14 -14 11 -20 -16 7 12 17
// OUTPUT: -20 -19 -17 -16 -14 -14 -14 -13 -12 -11 -11 -10 -8 -8 -7 -6 -4 -4 -4 -3 -3 -2 1 2 3 3 4 4 7 9 9 11 12 13 14 15 17 17 18 19 20 20

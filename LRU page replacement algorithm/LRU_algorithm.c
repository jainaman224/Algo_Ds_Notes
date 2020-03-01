#include<stdio.h>

int findLRU(int time[], int n){
  int i, minimum = time[0], pos = 0;
  for(i = 1; i < n; ++i){
    if(time[i] < minimum){
      minimum = time[i];
      pos = i;
    }
  }
  
  return pos;
}
int main()
{
int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0,hit=0;
  printf("Enter number of frames: ");
  scanf("%d", &no_of_frames);
  
  printf("Enter number of pages: ");
  scanf("%d", &no_of_pages);
  
  printf("Enter reference string: ");
  
for(i = 0; i < no_of_pages; ++i){
  scanf("%d", &pages[i]);
}
  for(i = 0; i < no_of_frames; ++i){
  frames[i] = -1;
}
for(i = 0; i < no_of_pages; ++i){
  flag1 = flag2 = 0;
  
  for(j = 0; j < no_of_frames; ++j){
    if(frames[j] == pages[i]){
      hit++;
       counter++;
       time[j] = counter;
        flag1 = flag2 = 1;
        break;
     }
  }
  
  if(flag1 == 0){
      for(j = 0; j < no_of_frames; ++j){
       if(frames[j] == -1){
         counter++;
         faults++;
         frames[j] = pages[i];
         time[j] = counter;
         flag2 = 1;
         break;
       }
    } 
  }
  
  if(flag2 == 0){
    pos = findLRU(time, no_of_frames);
    counter++;
    faults++;
    frames[pos] = pages[i];
    time[pos] = counter;
  }
  
  printf("\n");
  
  for(j = 0; j < no_of_frames; ++j){
    printf("%d\t", frames[j]);
  }
  }
  
  printf("\n\nTotal Page Faults = %d\n", faults);
  printf("\nTotal Page Hit = %d\n", hit);
  printf("\nTotal Page Hit Ratio = %f\n", (float)((float)hit/no_of_pages));
return 0;
}


// ------------ Result ---------------------------

// Enter number of frames: 5
// Enter number of pages: 6
// Enter reference string: 0 2 0 3 4 5

// 0   -1  -1  -1  -1
// 0   2   -1  -1  -1
// 0   2   -1  -1  -1
// 0   2   3   -1  -1
// 0   2   3   4   -1
// 0   2   3   4   5

// Total Page Faults = 5

// Total Page Hit = 1

// Total Page Hit Ratio = 0.166667
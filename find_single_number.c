#include <stdio.h>

int partition(int *nums, int low, int high) {
    int pindex = low, pivot = nums[high], i, tmp;
    for (i = low; i < high; i++) {
        if (nums[i] <= pivot) {
            tmp = nums[i];
            nums[i] = nums[pindex];
            nums[pindex] = tmp;
            pindex++;
        }
  }

        tmp = nums[pindex];
        nums[pindex] = nums[high];
       nums[high] = tmp;
    return pindex;
}
void quicksort(int *nums, int low, int high) {
    int pindex;
    if (low < high) {
        pindex = partition(nums, low, high);
        quicksort(nums, low, pindex-1);
        quicksort(nums,pindex+1,high);
    }
}
int singleNumber(int* nums, int numsSize){
    int i,j, s;
    quicksort(nums, 0, numsSize-1);
    
  for (i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }

  printf("\n");
  i = 0; j = 1;
  // 2 2 3 3 3 4 4 4 5 6 6 9 9 
  while(i < numsSize-2 && j <= numsSize-1) {
        if (nums[i] == nums[j]) {
            j++;
            s = 1;
        } else {
            if (s == 1) {
                i = j;
                j = j+1;
                s = 0;
            } else {
                return nums[i];
            }
        }
    }
    if (i == numsSize-1) {
      return nums[i];
    }
    return 0;
}

int main() {
int i;
int arr[] = {2,3,6,4,8,4,4,6,2,3,3,4,9,8};
int size = (sizeof(arr)/sizeof(arr[0]));

for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  } 

  printf("\n");
int num = singleNumber(arr,size);
printf("single --> %d\n", num);



}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SWAP(x,y){int t=x; x=y; y=t;}

int Rselect(int* arr, int n, int i){
  int pivot=0,j,k;
  int *left, *right;
  if (n==1)return arr[0];
  srand(time(NULL));
  pivot = rand() % n;
  //partition around pivot
  if (pivot != 0){
    SWAP(arr[0], arr[pivot])
  }
  k=1;
  for (j=1; j<n; j++){
    if (arr[j] < arr[0]){
      SWAP(arr[j],arr[k])
      k++;
    }
  }
  SWAP(arr[0], arr[k-1])

  if (k == i) return arr[k-1];
  if (k > i){
    //recurse left part
    left = malloc(sizeof(int)*k);
    for (j=0; j<k-1; j++){
      left[j] = arr[j];
    }

    // free(arr);
    return Rselect(left, k-1, i);
  }
  if (k < i){
    //recurse on right part
    right = malloc(sizeof(int)*(n-k));
    for (j=0; j<(n-k); j++){
      right[j] = arr[k+j];
    }

    // free(arr);
    return Rselect(right, n-k, i-k);
  }
  return -1;
}

int main(void){
  int a[5] = {4,3,1,5,2};
  int num = Rselect(a, 5, 5);
  printf("3rd smallest is %d\n",num);
}

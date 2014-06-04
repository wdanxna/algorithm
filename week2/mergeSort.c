#include<stdio.h>
#include<stdlib.h>


int* mergeSort(int *arr, int len){
    int i,j,k;
    int *left, *right, *result;
    if (len <= 1) return arr;

    left = (int*)malloc((len/2)*sizeof(int));
    right = (int*)malloc((len-(len/2)) * sizeof(int));

    for (i=0; i<len/2; i++){
      left[i] = arr[i];
    }
    j=0;
    for (i=(len/2); i<len; i++){
      right[j++] = arr[i];
    }

    left = mergeSort(left, len/2);
    right = mergeSort(right, len-(len/2));

    //merge step
    i = 0; j = 0;
    result = (int*)malloc(len*sizeof(int));

    for (k=0; k<len; k++){
      if (j >=(len-len/2) || (i < len/2 && left[i] < right[j])){
        result[k] = left[i];
        i++;
      } else {
        result[k] = right[j];
        j++;
      }
    }

    free(left);free(right);
    return result;
}

int main(void){
  int i;
  int a[10] = {9,8,2,6,7,4,3,2,1,0};
  int* result = mergeSort(a,10);
  for (i=0;i<10;i++){
    printf("%d ",result[i]);
  }
  printf("\n");
}

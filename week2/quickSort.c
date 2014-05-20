#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y){int t=x; x=y; y=t;}
static int count = 0;



int partition_left(int* arr, int left, int right){
  int i = left+1,j;
  int pivot = arr[left];

  for (j=left+1; j<=right; j++){
    if (arr[j] < pivot){
      SWAP(arr[i],arr[j])
      i++;
    }
  }
  SWAP(arr[left],arr[i-1])
  return i;
}

int partition_right(int* arr, int left, int right){
  SWAP(arr[right],arr[left])

  return partition_left(arr,left,right);
}

int getmedian(int* arr, int a, int b, int c){
  int va = arr[a], vb = arr[b], vc = arr[c];
  if ((vc < va && va <= vb)|| (vb < va && va <= vc))return a;
  if ((vc < vb && vb <= va) || (va < vb && vb <= vc))return b;
  if ((va < vc && vc <= vb) || (vb < vc && vc <= va))return c;
  return b;
}

int partition_median(int*arr, int left, int right){
  int len = right-left+1;
  int midpos = left+(len%2==0?(len/2-1):(len/2));
  int medianIndex = getmedian(arr, left, midpos, right);
  if (medianIndex != left){
    SWAP(arr[medianIndex], arr[left])
  }
  return partition_left(arr, left, right);
}


void quickSort(int* arr, int left, int right){
  int i;
  if (left >= right)return;
  count += right - left;

  i = partition_median(arr, left, right);
  // printf("%d\n",i);

  quickSort(arr, left, i-2);
  quickSort(arr, i, right);

}

int test_for_increment(int* a, int len){
  int i,start;
  if (len < 1)return 0;
  for (i=0; i<len-1; i++){
    if (a[i] > a[i+1]){
      printf("wrong at: %d (%d > %d)\n",i,a[i],a[i+1]);
      return 0;
    }
  }
  return 1;
}

int main(void){
  count = 0;
  if (1){
    char buf[100];
    int a[10000],i=0;
    FILE *fp;
    if ((fp = fopen("QuickSort.txt","r"))==NULL){
      printf("open failed!\n");
      return -1;
    }

    while (fgets(buf,100,fp)){
      a[i] = atoi(buf);
      i++;
    }
    fclose(fp);

    quickSort(a,0,9999);

    if (test_for_increment(a,10000)){
      printf("correct!\n");
      printf("%d\n",count);
    }
  }else{
    int i;
    int a[8] = {8,7,6,5,4,3,2,1};
    // partition(a,0,4);
    quickSort(a,0,7);
    for (i=0;i<8;i++){
      printf("%d ",a[i]);
    }
    // printf("%d\n",count);
  }
}

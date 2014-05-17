#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y){int t=x; x=y; y=t;}
static int count = 0;

void quickSort(int* arr, int left, int right){
  int p,i=left,j=0;
  if (left >= right)return;
  count += right - left;
  p = arr[left];

  while (i <= right){
    if (arr[i] > p){
      j = i + 1;
      while (j <= right){
        if (arr[j] < p){
          SWAP(arr[i],arr[j])
          i++;
        }
        j++;
      }
      break;
    }
    else{
      i++;
    }
  }
  i--;
  // printf("%d,%d\n",i,j);
  SWAP(arr[left],arr[i]);
  quickSort(arr, left, i-1);
  quickSort(arr, i+1, right);
}


int test_for_increment(int* a, int len){
  int i,start;
  if (len < 1)return 0;
  for (i=0; i<len-1; i++){
    if (a[i] > a[i+1])return 0;
  }
  return 1;
}

int main(void){
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
}

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

void MergeSort(int k[],int n){
	int i,left_min,left_max,right_min,right_max;
	int *temp =  (int *)malloc(sizeof(int)*n);
	for(i=1;i<n;i*=2){ //i 是 步长 
		for(left_min = 0;left_min < n - i; left_min = right_max){
			right_min = left_max = left_min+i;
			right_max = left_max + i;
			if(right_max>n){
				right_max = n;
			}
			int next = 0;
			while(left_min < left_max && right_min <right_max){
				if(k[left_min] < k[right_min]){
					temp[next++] = k[left_min++];
				}
				else{
					temp[next++] = k[right_min++];
				}
			}
			while(left_min < left_max){
				k[--right_max] = k[--left_max];
			}
			while(next > 0){
				k[--right_min] = temp[--next];
			}
		}	
	}
}
int main(){
	int i;
	int a[] = {5,8,4,0,2,3,1,6,9,7};
	MergeSort(a,10);
	printf("排序后:\n");
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	} 
	printf("\n\n");
	return 0;
}


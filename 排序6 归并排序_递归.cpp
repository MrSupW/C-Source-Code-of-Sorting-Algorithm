#include<stdio.h>
#define MAX_SIZE 100
//归并 并把结果存放到list1里面 
void Merging(int *list1,int list1_size,int *list2,int list2_size){
	int temp[MAX_SIZE];
	int i,j,k;
	i = j = k  = 0;
	while(i<list1_size && j<list2_size){
		if(list1[i] < list2[j]){  //如果要实现从大到小排序 则修改此处的符号即可 
			temp[k++] = list1[i++];
		}
		else {
			temp[k++] = list2[j++];	
		}
	}
	while(i<list1_size){
		temp[k++] = list1[i++];
	}
	while(j<list2_size){
		temp[k++] = list2[j++];
	}
	for(i = 0;i<(list1_size + list2_size);i++){
		list1[i] = temp[i];
	} 
}


void MergeSort(int k[],int n){
	if(n<=1) return;
	int *list1 = k;
	int list1_size = n/2;
	int *list2 = k+n/2;
	int list2_size = n - list1_size;
	MergeSort(list1,list1_size);
	MergeSort(list2,list2_size);
	Merging(list1,list1_size,list2,list2_size);
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

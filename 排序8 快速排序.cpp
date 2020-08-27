#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

void Swap(int k[],int low,int high){
	int temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}

int Partition(int k[],int low, int high){
	int point;
	point = k[low];
	while(low < high){
		while(low < high && k[high] >= point){ //若要实现从大到小排序，则需要改变此处的符号 比如这里改为<= 
			high--;
		}
		Swap(k,low,high);
		while(low < high && k[low] <= point){ //若要实现从大到小排序，则需要改变此处的符号 比如这里改为>=
			low++;
		}
		Swap(k,low,high);
	}
	return low;
}

void QSort(int k[], int low, int high){
	int point;
	if(low < high){
		point = Partition(k,low,high);
		QSort(k,low, point-1);
		QSort(k,point+1,high);
	}
}

void QuickSort(int k[],int n){
	QSort(k,0,n-1);
}
int main(){
	int i;
	int a[] = {5,8,4,0,2,3,1,6,9,7};
	QuickSort(a,10);
	printf("排序后:\n");
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	} 
	printf("\n\n");
	return 0;
}


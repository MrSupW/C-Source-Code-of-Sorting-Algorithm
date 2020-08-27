#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100


void Swap(int k[],int low, int high){
	int temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}

int Partition(int k[],int low,int high){
	int point ;
	int m = low + (high - low)/2;
	if(k[high] < k[low]){
		Swap(k,low,high);
	}
	if(k[m] > k[high]){
		Swap(k,m,high);
	}
	if(k[m] > k[low]){
		Swap(k,m,low);
	}
	point = k[low];
	while(low < high){
		while(low < high && k[high] >= point){
			high--;
		}
		k[low] = k[high]; // 优化后 
		while(low < high && k[low] <= point){
			low++;
		}
		k[high] = k[low]; //优化后 
	}
	k[low] = point;  //优化后 
	return low;
}

void QSort(int k[], int low, int high){
	int point;
	if(low<high){
		point = Partition(k,low,high);
		QSort(k,low,point-1);
		QSort(k,point+1,high);
	}
}

void QuickSort(int k[], int n){
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
	printf("\n");
	return 0;
}


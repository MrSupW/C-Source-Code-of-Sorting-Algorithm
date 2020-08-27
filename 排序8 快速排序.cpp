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
		while(low < high && k[high] >= point){ //��Ҫʵ�ִӴ�С��������Ҫ�ı�˴��ķ��� ���������Ϊ<= 
			high--;
		}
		Swap(k,low,high);
		while(low < high && k[low] <= point){ //��Ҫʵ�ִӴ�С��������Ҫ�ı�˴��ķ��� ���������Ϊ>=
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
	printf("�����:\n");
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	} 
	printf("\n\n");
	return 0;
}


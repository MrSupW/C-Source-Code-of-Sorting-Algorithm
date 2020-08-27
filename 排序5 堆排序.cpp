#include<stdio.h>
#include<stdlib.h>
void Swap(int a[], int i, int j ){
	int temp;
	temp = a[j];
	a[j] = a[i];
	a[i] = temp;
}


void HeapAdjust(int a[],int s ,int n){
	int i,temp;
	temp = a[s];
	for(i=s*2;i<=n;i*=2){
		if(i<n && a[i]<a[i+1]) i++;  	//若要实现从大到小排序 改这一行的符号即可 
		if(temp >= a[i]) break;  		//若要实现从大到小排序 改这一行的符号即可
		a[s] = a[i];
		s = i; 
	}
	a[s] = temp;
} 

void HeapSort(int a[],int n){
	int i;
	for(i=n/2;i>0;i--){
		HeapAdjust(a,i,n);
	}
	for(i=n;i>1;i--){
		Swap(a,1,i);
		HeapAdjust(a,1,i-1);
	}
} 

int main(){
	int i;
	int a[] = {-1,5,8,4,0,2,3,1,6,9,7};
	HeapSort(a,10);
	printf("排序后:\n");
	for(i=1;i<11;i++){
		printf("%d ",a[i]);
	} 
	printf("\n\n");
	return 0;
}

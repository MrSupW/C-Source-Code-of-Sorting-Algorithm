#include<stdio.h>
#include<stdlib.h>

void InsertSort(int a[],int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		if (a[i-1] > a[i]){
			temp = a[i];
			for(j = i-1; a[j] > temp;j--){
				a[j+1] = a[j];
			}
			a[j+1] = temp;
		}
	}
} 

int main(){
	int i;
	int a[] = {5,8,4,0,2,3,1,6,9,7};
	InsertSort(a,10);
	printf("≈≈–Ú∫Û:\n");
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	} 
	printf("\n\n");
	return 0;
}

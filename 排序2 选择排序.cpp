#include<stdio.h>
#include<stdlib.h>

void SelectSort(int a[],int n){
	int min,i,j;
	int count1 = 0,count2 = 0;
	for(i=0;i<n;i++){
		min = i;
		for(j = i+1;j<n;j++){
			count1 ++;
			if(a[j]<a[min]){
				min = j;
			}
		}
		if(i!=min){
			count2++;
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
	printf("一共进行了%d次比较，%d次交换...\n",count1,count2);
} 

int main(){
	int i;
	int a[] = {5,8,4,0,2,3,1,6,9,7};
	SelectSort(a,10);
	printf("排序后:\n");
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	} 
	printf("\n\n");
	return 0;
}

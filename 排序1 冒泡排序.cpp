#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int a[],int n){
	int flag = 1, i, j,count1 = 0,count2 = 0;
	for(i=0;i<n && flag;i++){
		flag = 0;
		for(j = 0;j<n-1-i;j++){
			count1 ++;
			if(a[j]>a[j+1]){
				count2++;
				flag = 1;
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp; 
			}
		}
	}
	printf("共进行了%d次比较，%d次移动...\n",count1,count2); 
} 

int main(){
	int i;
	int a[] = {5,8,4,0,2,3,1,6,9,7};
	BubbleSort(a,10);
	printf("排序后:\n");
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	} 
	printf("\n\n");
	return 0;
}

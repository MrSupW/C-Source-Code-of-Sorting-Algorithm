#include<stdio.h>
#include<stdlib.h>

void ShellSort(int a[],int n){
	int i,j,temp,gap = n;
	do {
		gap = gap/3 + 1;
		for(i=gap;i<n;i++){
			if (a[i-gap] > a[i]){
				temp = a[i];
				for(j = i-gap; a[j] > temp;j-=gap){
					a[j+gap] = a[j];
				}
			a[j+gap] = temp;
		}
	}
	}while(gap > 1);
} 

int main(){
	int i;
	int a[] = {5,8,4,0,2,3,1,6,9,7};
	ShellSort(a,10);
	printf("≈≈–Ú∫Û:\n");
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	} 
	printf("\n\n");
	return 0;
}

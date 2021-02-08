#include<stdio.h>

int quicksort(int *array,int l,int r){
		int tmp = array[l];
		int i = l;
		int j = r;
		while(i<j){
			while(i<j && array[j] < tmp){
				j--;
			}
			array[i] = array[j];
			while(i<j && array[i] >= tmp){
				i++;
			}
			array[j] = array[i];
		}
		array[i] = tmp;
		return i;
}

int findKMax(int *array,int l,int r,int k){
	if(l>=r){
		return array[l];
	}
	int temp = quicksort(array,l,r);
	if(temp == k-1){
		return array[temp];
	}
	else if(temp > k-1){
		return findKMax(array,l,temp-1,k);
	}
	else{
		return findKMax(array,temp+1,r,k);
	}
}

int main(){
	int num[15] = {1, 2, 3, 3, 4, 4, 4, 4, 4, 5, 5, 8, 10, 12};
    int start = 0;
    int end =13;
    int i;
    for(i = 0;i<=end;i++){
    	printf("%d ",num[i]);
	}
	printf("\n"); 
    int res = findKMax(num,0,13,12);
    printf("k max:%d\n",res);
    for(i = 0;i<=end;i++){
    	printf("%d ",num[i]);
	}
	printf("\n"); 
	return 0;
} 



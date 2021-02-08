#include<stdio.h>

int l = 14;

void swap(int *a,int *b){
	int tmp = (*a);
	(*a) = (*b);
	(*b) = tmp;
	return;
}

void PrintArr(int *arr,int length){
	int i;
	for(i = 0;i< length;i++){
    	printf("%d ",arr[i]);
	}
	printf("\n"); 
}

void BigHeadAdjust(int *array,int index,int length){
	int l_child = 2*index + 1;
	int r_child = 2*index + 2;
	int max = index;
	if(l_child < length && array[max] < array[l_child]){
		max = l_child;
	}
	if(r_child < length && array[max] < array[r_child]){
		max = r_child;
	}
	if(max != index){
		swap(&array[max],&array[index]);
		BigHeadAdjust(array,max,length);
	}
}

void HeapSort_Up(int *array, int length){
	int i;
	for(i = (length/2) - 1;i>=0;i--){
		BigHeadAdjust(array,i,length);
	}
	for(i = length-1;i>=0;i--){
		swap(&array[0],&array[i]);
		BigHeadAdjust(array,0,i);
	}
}

int main(){
	int num[15] = {4,6,8,5,9,5,4,3,3,2,1,1,1,1};
    PrintArr(num,l);
    HeapSort_Up(num,l);
    PrintArr(num,l);
	return 0;
} 



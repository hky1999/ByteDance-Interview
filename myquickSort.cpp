#include<stdio.h>

void quicksort(int *array,int l,int r){
	if(l>=r){
		return;
	}
	int tmp = array[l];
	int i = l;
	int j = r;
	while(i<j){
		while(i<j && tmp < array[j]){
			j--;
		}
		array[i] = array[j];
		while(i<j && array[i] <= tmp){
			i++;
		}
		array[j] = array[i];
	} 
	array[i] = tmp;
	quicksort(array,l,i-1);
	quicksort(array,i+1,r);
}


int main(){
	int num[15] = {10,1,2,3,6,5,4,3,3,2,1,1,1,1};
    int start = 0;
    int end =13;
    int i;
    for(i = 0;i<=end;i++){
    	printf("%d ",num[i]);
	}
	printf("\n"); 
    quicksort(num,0,13);
    for(i = 0;i<=end;i++){
    	printf("%d ",num[i]);
	}
	printf("\n"); 
	return 0;
} 

/**
//堆调整 大堆顶，将最大值放在根结点
void BigHeadAdjust(int *arr,int index,int length)
{
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	int max = index;
	if (lchild<length&&arr[lchild]>arr[max])
	{
		max = lchild;
	}
	if (rchild<length&&arr[rchild]>arr[max])
	{
		max = rchild;
	}
	if (max != index)
	{
		Swap(&arr[max], &arr[index]);
		BigHeadAdjust(arr, max, length);
	}
	return;
}
 
//堆排序，采用大顶堆 升序
void HeapSort_Up(int *arr, int length)
{
	//初始化堆，将每个非叶子结点倒叙进行大顶堆调整。
	//循环完毕 初始大顶堆（每个根结点都比它孩子结点值大）形成
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		BigHeadAdjust(arr, i, length);
	}
	printf("大堆顶初始化顺序：");
	PrintArr(arr, length);
	//将堆顶值放到数组尾部，然后又进行大堆顶调整，一次堆调整最值就到堆顶了。 
	for (int i = length - 1; i >= 0; i--)
	{
		Swap(&arr[0], &arr[i]);
		BigHeadAdjust(arr, 0, i);
	}
	return;
void _quicksort(int *array,int l,int r){
	if(l<r){
		int temp = array[l];
		int i = l;
		int j = r;
		while(i<j){
			while(i<j && array[j] < temp){
				j--;
			}
			array[i] = array[j];
			while(i<j && array[i] >= temp){
				i++;
			}
			array[j] = array[i];
		}
		array[i] = temp;
		quicksort(array,l,i-1);
		quicksort(array,i+1,r);
	}
	else{
		return;
	}
}
}*/

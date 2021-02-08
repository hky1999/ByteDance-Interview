#include<stdio.h>

int l = 5;

void Swap(int *a,int *b){
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
	int i;
	for (i = length / 2 - 1; i >= 0; i--)
	{
		printf("%d l:%d r:%d\n",i,2*i+1,2*i+2);
		PrintArr(arr,length);
		BigHeadAdjust(arr, i, length);
		PrintArr(arr,length);
	}
	printf("大堆顶初始化顺序：");
	PrintArr(arr, length);
	//将堆顶值放到数组尾部，然后又进行大堆顶调整，一次堆调整最值就到堆顶了。 
	for (i = length - 1; i >= 0; i--)
	{
		Swap(&arr[0], &arr[i]);
		printf("%d: [%d] :::\n",i,arr[i]);
		PrintArr(arr, length);
		BigHeadAdjust(arr, 0, i);
		PrintArr(arr, length);
	}
	return;
}

int main(){
	int num[15] = {4,6,8,5,9,5,4,3,3,2,1,1,1,1};
    PrintArr(num,l);
    HeapSort_Up(num,l);
    PrintArr(num,l);
	return 0;
} 



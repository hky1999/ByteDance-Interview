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

//�ѵ��� ��Ѷ��������ֵ���ڸ����
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
 
//�����򣬲��ô󶥶� ����
void HeapSort_Up(int *arr, int length)
{
	//��ʼ���ѣ���ÿ����Ҷ�ӽ�㵹����д󶥶ѵ�����
	//ѭ����� ��ʼ�󶥶ѣ�ÿ������㶼�������ӽ��ֵ���γ�
	int i;
	for (i = length / 2 - 1; i >= 0; i--)
	{
		printf("%d l:%d r:%d\n",i,2*i+1,2*i+2);
		PrintArr(arr,length);
		BigHeadAdjust(arr, i, length);
		PrintArr(arr,length);
	}
	printf("��Ѷ���ʼ��˳��");
	PrintArr(arr, length);
	//���Ѷ�ֵ�ŵ�����β����Ȼ���ֽ��д�Ѷ�������һ�ζѵ�����ֵ�͵��Ѷ��ˡ� 
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



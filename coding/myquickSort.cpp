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
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		BigHeadAdjust(arr, i, length);
	}
	printf("��Ѷ���ʼ��˳��");
	PrintArr(arr, length);
	//���Ѷ�ֵ�ŵ�����β����Ȼ���ֽ��д�Ѷ�������һ�ζѵ�����ֵ�͵��Ѷ��ˡ� 
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

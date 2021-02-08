#include <stdio.h>

#define LEN (100)

int binarySearch(int *num,int start,int end,int target,int isFirstFlag){
    int mid;
    while(start<=end){
        mid = (start+end)/2;
        if(num[mid]>target){
            end = mid-1;
        }
        else if(num[mid]< target){
            start = mid+1;
        }
        else if(num[mid] == target && isFirstFlag){
            end = mid-1;
        }
        else if(num[mid] == target && !isFirstFlag){
           start = mid+1;
        }
    }
    return (isFirstFlag) ? start:end;
}

int main(){
    int num[LEN] = {1, 2, 3, 3, 4, 4, 4, 4, 4, 5, 5, 8, 10, 12};
    int start = 0;
    int end = 13;
    int target = 8;
    int i;
    for(i = 0;i<=end;i++){
    	printf("%d ",num[i]);
	}
	printf("\n"); 
    int leftIndex = binarySearch(num,start,end,target,1);
    int rightIndex = binarySearch(num,start,end,target,0);
    printf("%d %d \n",leftIndex,rightIndex);
    printf("res: %d\n",rightIndex - leftIndex + 1);
    return rightIndex - leftIndex;
}

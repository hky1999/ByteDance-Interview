#include<stdio.h>
#define LEN (20)

void quicksort(int *num,int l,int r){
	int first = l;
	int last = r;
	int pri = num[first];
	if(l>=r){
		return;
	}
	while(first < last){
		while(first < last && num[last] > pri){
			last--;
		}
		num[first] = num[last];
		while(first < last && num[first] <= pri){
			first++;
		}
		num[last] = num[first];
	}
	num[first] = pri;
	quicksort(num,l,first-1);
	quicksort(num,first+1,r);
}


int main(){
	int num[LEN] = {10,1,2,3,6,5,4,3,3,2,1,1,1,1};
    int start = 0;
    int end =13;
    int i;
    for(i = 0;i<=end;i++){
    	printf("%d ",num[i]);
	}
	printf("\n"); 
    quicksort(num,start,end);
    for(i = 0;i<=end;i++){
    	printf("%d ",num[i]);
	}
	printf("\n"); 
	return 0;
} 

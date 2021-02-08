#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int left = 1024 - n;
    int res = 0;
    int tmp;
    tmp = left/64;
    res += tmp;
    left = left - tmp*64;
    //printf("get %d 64coin, left %d\n",tmp,left);
    tmp = left/16;
    res += tmp;
    left = left - tmp*16;
    //printf("get %d 16coin, left %d\n",tmp,left);a
    tmp = left/4;
    res += tmp;
    left = left - tmp*4;
    //printf("get %d 4coin, left %d\n",tmp,left);
    tmp = left;
    res += tmp;
    left = left - tmp*1;
    //printf("get %d 1coin, left %d\n",tmp,left);
    printf("%d\n",res);
    return 0;
}

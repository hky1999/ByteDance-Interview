#include<stdio.h>
#include<stdlib.h>
 

int main(){
    long long n,d;
    long long b[100000];
    long long sum = 0;
    scanf("%lld %lld",&n,&d);
    long long i = 0;
    long long k = 2;
    for(i = 0;i<n;i++){
        scanf("%lld",&b[i]);
    }
    for(i = 0;i<n-2;i++){
        for(;b[k] - b[i] <= d && k<n;k++){ 
        }
        printf("find begin:%lld end:%lld mid:%lld\n",i,k,k-i-1);
        sum += (k-i-1)*(k-i-2)/2;
    }
    printf("%lld\n",sum % 99997867);
    return 0;
}

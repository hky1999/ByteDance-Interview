#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main(){
    int n;
    int i,j;
    char in[1000];
    scanf("%d",&n);
    for(i = 0;i<n;i++){
        memset(in,0,1000);
        scanf("%s",in);
        int l = strlen(in);
        for(j = 0;j<l;j++){
            if(in[j] != in[j+1] || j>=l-2){
                printf("%c",in[j]);
            }
            // AA
            else{
                // £¨AABBÐÍ£©
                if(j<l-3 && in[j+2] == in[j+3] && in[j+1] != in[j+2]){
                    printf("%c%c%c",in[j],in[j+1],in[j+3]);
                    char tmp = in[j+3];
                    j+=3;
                    while(in[j] == tmp){
                    	j++;
					}
					j--;
                }
                else if(j<l-2 && in[j+1] == in[j+2]){
                    char tmp = in[j];
                    printf("%c%c",in[j],in[j+1]);
                    while(in[j] == tmp){
                        j++;
                    }
                    if(j<l-1 && in[j] == in[j+1]){
                    	tmp = in[j];
                    	printf("%c",tmp);
                    	while(in[j] == tmp){
                    		j++;
						}
					}
                    //printf("[%c][%c]",in[j],in[j+1]);
                    j--;
                    //printf("[%c][%c]",in[j],in[j+1]);
                }
                else{
                	printf("%c",in[j]);
				}
            }
        }
        printf("\n");
    }
    return 0;
}

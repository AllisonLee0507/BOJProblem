#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int main(){
    int n, i, result = 0, pos = 0, t=0;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++){
        t = 0;
        pos = i;
        while(pos != -1){
            if(t==n){
                break;
            }
            pos = a[pos]-1;
            t++;
        }
        if(pos==-1){
            result++;
        }
    }
    printf("%d",result);
}
#endif

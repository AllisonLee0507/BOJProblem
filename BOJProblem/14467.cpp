#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int arr[101];
int main(){
    int n, sum = 0;
    int a, b;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++){
        arr[i] = -1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        scanf("%d", &b);
        if(arr[a] >=0 & arr[a] != b){
            sum++;
        }
        arr[a] = b;
    }
    printf("%d", sum);
}
#endif

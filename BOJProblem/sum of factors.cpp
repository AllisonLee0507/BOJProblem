#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(){
    int n;
    int i, ans;
    i = 0;
    ans = 0;
    
    scanf("%d", &n);
    
    for(int i = 1; i<=n; i++){
        if(n%i==0){
            ans+=i;
        }
    }
    printf("%d\n", ans);
}
#endif

#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int state[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int n, cnt;
int isprime(int x){
    if(x < 2){
        return 0;
    }
    for(int i = 2; i*i <= x; i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
void f(int num, int len){
    if(len == n){
        if(num == 0){
            return;
        }
        int temp = num;
        while(temp){
            if(!isprime(temp)){
                return;
            }
            temp /= 10;
        }
        cnt++;
        printf("%d\n", num);
        return;
    }
    else{
        for(int i = 0; i<9; i++){
            
            f(num*10+state[i], len+1);
        }
//        f(num*10+1, len+1);
//        f(num*10+2, len+1);
//        f(num*10+3, len+1);
//        f(num*10+4, len+1);
//        f(num*10+5, len+1);
//        f(num*10+6, len+1);
//        f(num*10+7, len+1);
//        f(num*10+8, len+1);
//        f(num*10+9, len+1);
        
    }
}
int main(){
    scanf("%d", &n);
    f(0, 0);
    printf("%d", cnt);
}

#endif

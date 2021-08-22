#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <algorithm>
int gift[30], chk[30], A, B, C, n, S;

int comp(int a, int b){
    return a>b;
}

void solve(int no, int a, int b, int c){
    int stateA[] = {0, 0, gift[no]};
    int stateB[] = {0, gift[no], 0};
    int stateC[] = {gift[no],0, 0};
    
    if(no<n){
        for(int i = 0; i < 3; i++){
            solve(no+1, a+stateA[i], b+stateB[i], c+stateC[i]);
        }
//        solve(no+1, a, b, c+gift[no]);
//        solve(no+1, a, b+gift[no], c);
//        solve(no+1, a+gift[no], b, c);
    }
    else if(a>=b && b>= c){
        A = a, B = b, C = c;
    }
}

int main(){
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; S+=gift[i++]){
        scanf("%d", &gift[i]);
    }
    std::sort(gift, gift+n, comp);
    solve(0,0,0,0);
    printf("%d %d %d\n", A, B, C);
    return 0;
}
#endif

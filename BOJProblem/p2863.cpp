#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(){

    int A, B, C, D;
    int temp, maxcnt;
    double val, max=0;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    for(int i=0; i<4; i++){
        val = (double)(A*D+B*C)/(C*D);
        if(max < val){
            max = val;
            maxcnt = i;
        }
        temp = A;
        A = C;
        C = D;
        D = B;
        B = temp;
    }
    printf("%d \n", maxcnt);

    return 0;
}

#endif

#if 0
#include <iostream>
using namespace std;

int main(){

    int A, B, C, D;
    int temp, maxcnt;
    double val, max=0;
    cin >> A >> B >> C >> D;
    for(int i=0; i<4; i++){
        val = (double)(A*D+B*C)/(C*D);
        if(max < val){
            max = val;
            maxcnt = i;
        }
        temp = A;
        A = C;
        C = D;
        D = B;
        B = temp;
    }
    cout << maxcnt << endl;

    return 0;
}
#endif

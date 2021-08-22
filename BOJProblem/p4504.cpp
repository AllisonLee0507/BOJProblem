#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    while(1){
        int var;
        scanf("%d", &var);
        if (var == 0){
            break;
        }
        printf("%d is %sa multiple of %d.\n", var, var%N ? "NOT " : "", N );
    }
}

#endif

#if 0
#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(1){
        int var;
        cin >> var;
        if (var == 0){
            break;
        }
        if (var%N != 0){
            cout << var << " is NOT a multiple of " << N << ".\n";
        }
        else if (var%N == 0){
            cout << var << " is a multiple of " << N << ".\n";
        }
    }
}

#endif


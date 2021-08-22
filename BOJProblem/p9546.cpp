#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <math.h>
int main(){
    int K, T, i;
    double N;
    scanf("%lf", &N);
    i = 0;
    for (i=0; i<N; i++){
        scanf("%d", &K);
        T = pow(2.0, K) -1;
        printf("%d\n", T);
    }
}
#endif

#if 0
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int K, T, i;
    double N;
    cin >> N;
    i = 0;
    for (i=0; i<N; i++){
        cin >> K;
        T = pow(2.0, K) -1;
        cout << T << endl;
    }
}
#endif

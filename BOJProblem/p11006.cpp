#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int main(){
    int U, T, A, B;
    int N;
    int i = 0;
    scanf("%d", &N);
    for(i = 0; i<N; i++){
        scanf("%d %d", &A, &B);
        T = A - B;
        U = B - T;
        printf("%d %d\n", U, T);
    }
}
#endif

#if 0
#include <iostream>
using namespace std;
int main(){
    int U, T, A, B;
    int N;
    int i = 0;
    cin >> N;
    for(i = 0; i<N; i++){
        cin >> A >> B;
        T = A - B;
        U = B - T;
        cout << U << " " << T << endl;
    }
}
#endif

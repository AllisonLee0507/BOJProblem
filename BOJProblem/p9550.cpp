#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int main(){
    int T, B, N, K, C, A;
    int i = 0;
    int j = 0;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        C = 0;
        scanf("%d %d", &N, &K);
        for(j=0; j<N; j++){
            scanf("%d", &A);
            B = A/K;
            C = C + B;
        }
        printf("%d \n",C);
    }
}
#endif

#if 0
#include <iostream>
using namespace std;

int main(){
    int T, B, N, K, C, A;
    int i = 0;
    int j = 0;
    cin >> T;
    for(i=0; i<T; i++)
    {
        C = 0;
        cin >> N >> K;
        for(j=0; j<N; j++){
            cin >> A;
            B = A/K;
            C = C + B;
        }
        cout << C << endl;
    }
}
#endif


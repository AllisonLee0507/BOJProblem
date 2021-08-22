#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int main(){
    int T;
    int i;
    i = 0;
    scanf("%d", &T);
    for (i = 0; i<T; i++){
        int V, E, S;
        scanf("%d %d", &V, &E);
        S = 2 - V + E;
        printf("%d \n", S);
    }
}
#endif

#if 0
#include <iostream>
using namespace std;
int main(){
    int T;
    int i;
    i = 0;
    cin >> T;
    for (i = 0; i<T; i++){
        int V, E, S;
        cin >> V >> E;
        S = 2 - V + E;
        cout <<  S << endl;
    }
}
#endif

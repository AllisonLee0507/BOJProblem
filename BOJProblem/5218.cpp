#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>
#include <cstring>
using namespace std;

int main(){

    int T;
    char A[21], B[21];
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        scanf("%s %s", A, B);
        printf("Distances:");
        for(int i=0; i<strlen(A); i++)
            printf(" %d", (26+B[i]-A[i])%26);
        putchar('\n');
    }

    return 0;
}
#endif

#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <string.h>
#include <cstdio>
using namespace std;
int n, d[26], e[2][26], i, j;
int a(int x, int y){
    return x>y?x:y;
}
char s[11];
int main(){
    scanf("%d", &n);
    while(n--){
        memset(e, 0, sizeof(e));
        for(j = 0; j<2; j++){
            scanf("%s",s);
            for(i=0; s[i]; i++){
                e[j][s[i]-'a']++;
            }
        }
        for(i = 0; i<26; i++){
            d[i] += a(e[0][i], e[1][i]);
        }
    }
    for(i = 0; i<26; i++){
        printf("%d\n", d[i]);
    }
}
#endif

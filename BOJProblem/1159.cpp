#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int main(){
    int N, cnt[26] = {0};
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        char S[31];
        scanf("%s", S);
        cnt[S[0]- 'a']++;
    }
    bool impossible = true;
    for(int i = 0; i<26; i++){
        if(cnt[i] >= 5){
            impossible = false;
            putchar('a' + i);
        }
    }
    if(impossible){
        puts("PREDAJA"); 
    }
}
#endif

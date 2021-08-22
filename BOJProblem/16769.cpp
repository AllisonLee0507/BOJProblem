#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(){
    int c[5], m[5];
    int i;
    for(i = 0; i < 3; i++){
        scanf("%d%d", &c[i], &m[i]);
    }
    for(i = 0; i < 100; i++){
        if(c[(i+1)%3]-m[(i+1)%3]>=m[i%3]){
            m[(i+1)%3] += m[i%3];
            m[i%3] = 0;
        }
        else{
            m[i%3] -= c[(i+1)%3] - m[(i+1)%3];
            m[(i+1)%3] = c[(i+1)%3];
        }
    }
    printf("%d\n%d\n%d", m[0], m[1], m[2]);
    
    
}
#endif

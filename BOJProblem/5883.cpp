#define _CRT_SECURE_NO_WARNINGS

#if 0
#include <stdio.h>

int id[1005];
int get_largest_block(int n, int idignore){
    int maxBlockSize = 0;
    int curBreed = -1;
    int curSize = 0;
    for(int i = 0; i<n; i++){
        if(id[i] != idignore){
            if(curBreed == id[i]){
                curSize++;
            }
            else{
                curBreed = id[i];
                curSize = 1;
            }
            if(curSize > maxBlockSize){
                maxBlockSize = curSize;
            }
        }
    }
    return maxBlockSize;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &id[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int size = get_largest_block(n, id[i]);
        if(size > ans){
            ans = size;
        }
    }
    printf("%d\n", ans);
}
#endif

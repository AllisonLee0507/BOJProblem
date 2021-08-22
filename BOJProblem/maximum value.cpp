#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int arr[9][9];

int main(){
//    int arr[9][9];
    int i, j, max;
    max = -9999999;
    i = j = 0;
    for(i = 0; i <= 9; i++){
        for(j = 0; j <= 9; j++){
            arr[i][j] = 0;
        }
    }
    
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            scanf("%d", &arr[i][j]);
            if(max < arr[i][j]){
                max = arr[i][j];
            }
        }
    }
    printf("%d", max);
    for(i = 0; i <= 9; i++){
        for(j = 0; j <= 9; j++){
            if(arr[i][j] == max){
                printf("\n%d %d", i+1, j+1);
            }
        }
    }
}
#endif

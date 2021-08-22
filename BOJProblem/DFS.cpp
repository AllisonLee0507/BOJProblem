#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#define MAX_VERTEX 20
int vertex;
int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX];
void depthfirstseaerch(int v){
    
    
}
int main(){
    int T, test_case, start, v1, v2, i, j;
    scanf("%d", &T);
    for(test_case= 1; test_case<=T; test_case++){
        for(i = 0; i < MAX_VERTEX; i++){
            for(j = 0; j < MAX_VERTEX; j++){
                map[i][j] = 0;
            }
            visit[i] = 0;
        }
        scanf("%d %d", &vertex, &start);
        while(true){
            scanf("%d %d", &v1, &v2);
            if(v1 == -1 && v2 == -1){
                break;
            }
            map[v1][v2] = map[v2][v1] = 1;
        }
        printf("#%d", test_case);
    }
    
}
#endif

#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

struct point{
    int x;
    int y;
    int m;
};

typedef struct point POINT;

POINT QUEUE[100000];

int N;
int arr[300][300];
int result[300*300];
int StartX, StartY;
int EndX, EndY;
int dCol[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dLow[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int safe(int low, int col){
    return(low >= 0 && low < N && col >= 0 && col < N);
}
int BFS(int x, int y){
    int front = 0;
    int rear = 0;
    int min = 10000000;
    
    QUEUE[rear].x = x;
    QUEUE[rear].y = y;
    QUEUE[rear].m = 0;
    
    rear++;
    
    while(front < rear){
        int Nx = QUEUE[front].x;
        int Ny = QUEUE[front].y;
        int Nm = QUEUE[front].m;
        
        for(int i = 0; i < 8; i++){
            int NNx = Nx + dLow[i];
            int NNy = Ny + dCol[i];
            
            if(arr[NNx][NNy] == 0 && safe(NNx, NNy)){
                arr[NNx][NNy] = 1;
                
                QUEUE[rear].x = NNx;
                QUEUE[rear].y = NNy;
                QUEUE[rear].m = Nm + 1;
                
                if(QUEUE[rear].x == EndX && QUEUE[rear].y == EndY){
                    return QUEUE[rear].m;
                }
                rear++;
            }
        }
        front++;
    }
    return QUEUE[front - 1].m;
}
int main(){
    int test_case;
    int t = 0;
    
    scanf("%d", &test_case);
    
    while(test_case--){
        scanf("%d", &N);
        scanf("%d%d", &StartX, &StartY);
        scanf("%d%d", &EndX, &EndY);
        
        if(StartX == EndX && StartY == EndY){
            result[t] = 0;
            t++;
        }
        else{
            arr[StartX][StartY] = 1;
            result[t] = BFS(StartX, StartY);
            t++;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                arr[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < t; i++){
        printf("%d\n", result[i]);
    }
    
    return 0;
}
#endif

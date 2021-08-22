#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//bool isPrime(int k){
//    int cnt = 0;
//    for(int i=1; i<=k; i++){
//        if(k%i==0){
//            cnt++;
//        }
//    }
//    return cnt==2;
//}

//bool isPrime(int k){
//    int cnt = 0;
//    for(int i = 1; i <= k; i++){
//        if(k%i==0){
//            cnt++;
//        }
//        if(cnt > 2){
//            break;
//        }
//    }
//    return cnt==2;
//}

//bool isPrime(int k){
//    int cnt = 0;
//    for(int i = 1; i <= k && cnt <= 2; i++){
//        if(k%i == 0){
//            cnt++;
//        }
//    }
//    return cnt==2;
//}
//
//bool isPrime(int k){
//    int cnt=0;
//    for(int i =2; i<k; i++){
//        if(k%i == 0){
//            return false;
//        }
//    }
//    cnt++;
//    return true;
//}

void isPrime(int k){
    int *arr;
    int count;
    count = 0;
    arr = (int*)malloc(sizeof(int)*100);
    int i = 0;
    int j = 0;
    for(int i = 2; i <= 100; i++){
        arr[i] = i;
    }
    
    for(i = 2; i <= 100; i++){
        for(j = 2; j<= 100; j++){
            if(arr[j]!=i&&arr[j]%i==0){
                arr[j] = 0;
            }
        }
    }
    for(i = 2; i <= k; i++){
        if(arr[i]!= 0){
            printf("%d ", arr[i]);
        }
    }
    printf("%d", i);
}
int main(void){
    clock_t start, end;
    int N;
    scanf("%d", &N);
    start = clock();
    isPrime(N);
    end = clock();
    
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\n %lf", time);
}

//
//
//int main(){
//    int N, count, sum;
//    sum = 0;
//    int i;
//    i = 0;
//    scanf("%d", &N);
//    count = 0;
//
//    for(i = 2; i < 100000; i++){
//        if(isPrime(i) == true){
//            count++;
//        }
//        if(count == N){
//            break;
//        }
//    }
//    printf("%d", i);
//
//}
#endif

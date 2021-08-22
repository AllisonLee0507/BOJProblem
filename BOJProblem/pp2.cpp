#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;
int N;
int pi[101];
int Sum[101];
int result;
int num;

int main(){
   scanf("%d", &N);
   for (int i = 1; i <= N; i++){
      scanf("%d", &pi[i]);
   }
   for (int i = 0; i < N+1; i++){
      if (i == 0)
         Sum[i] = 0;
      else
         Sum[i] = Sum[i - 1] + pi[i];
   }
    for (int i = 1; i < N+1; i++){
      for (int j = i; j < N+1; j++){
         for (int n = i; n <= j; n++){
             num = pi[n] * (1 + j - i);
            if (num == Sum[j] - Sum[i - 1]){
               result++;
               break;
            }
         }
      }
    }
   printf("%d", result);
   return 0;
}
#endif

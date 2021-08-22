#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <string.h>
int main(){
    while(1){
        char N[6];
        int x;
        int i = 0;
        int result = 1;
        scanf("%s", N);
        if(N[0] == '0'){
            break;
        }
        x = (int)strlen(N);
        for(i = 0; i<x; i++){
            if(N[i] != N[x-i-1]){
                result = 0;
                break;
            }
            
        }
        (result > 0) ? printf("yes\n") : printf("no\n");
    }
    return 0;
}
#endif 
#if 0
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    while(1){
        string N;
        int x;
        int i = 0;
        bool result = true;
        //scanf("%s", N)
        cin >> N;
        if(N[0] == '0'){
            break;
        }
        //x = (int)strlen(N);
        x = N.length();
        for(i = 0; i<x; i++){
            if(N[i] != N[x-i-1]){
                result = false;
                break;
            }
            
        }
        (result > 0) ? printf("yes\n") : printf("no\n");
    }
    return 0;
}
#endif


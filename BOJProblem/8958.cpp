#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <string.h>

int main(){
    char x[81];
    int n, i, j, t, count, score;


    scanf("%d", &n);
    for(i = 0; i<n; i++){
        scanf("%s", x);
        t = (int)strlen(x);
        count = 0;
        score = 0;
        for(j = 0; j<t; j++){
            if(x[j] == 'O'){
                count++;
                score = score + count;
            }
            else{
                count = 0;
            }
        }
        printf("%d\n", score);
    }
}
#endif

#if 0
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
    string x;
    int n, i, j, t, count, score;


    scanf("%d", &n);
    for(i = 0; i<n; i++){
        //scanf("%s", x);
        cin >> x;
        //t = (int)strlen(x);
        t = x.length();
        count = 0;
        score = 0;
        for(j = 0; j<t; j++){
            if(x[j] == 'O'){
                count++;
                score = score + count;
            }
            else{
                count = 0;
            }
        }
        printf("%d\n", score);
    }
}
#endif

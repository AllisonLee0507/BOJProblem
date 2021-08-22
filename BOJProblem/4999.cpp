#if 0
#include <stdio.h>
#include <string.h>

int main(){
    char a[1000];
    char b[1000];
    int x, y;
    scanf("%s%s", a, b);
    x = (int)strlen(a);
    y = (int)strlen(b);
    if(x >= y){
        printf("go");
    }
    else{
        printf("no");
    }
    return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h>

int main(){
    char a[1000];
    char b[1000];
    int x, y;
    scanf("%s%s", a, b);
    x = (int)strlen(a);
    y = (int)strlen(b);
//    if(x >= y){
//        printf("go");
//    }
//    else{
//        printf("no");
//    }
    (x >= y)?(printf("go")):(printf("no"));
    return 0;
}
#endif

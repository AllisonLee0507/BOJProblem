#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
    string N;
    int s, i, j, len, count;
    count = 0;
    cin >> s;
    for (i=0; i<s; i++){
        cin >> N;
        len = (int)N.length();
        for(j = 0; j<len; j++){
            if(N[j] == '('){
                count++;
            }
            else if(N[j] == ')'){
                count--;
            }
        }
        if (count == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
#endif

//STL
#if 0
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void){
    stack<char> st;
    string str;
    int flag = 1;
    int n;
    
    cin >> n;
    
    while(n--){
        while(!st.empty()){
            st.pop();
        }
        flag = 1;
        cin >> str;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == ')'){
                st.push(str[i]);
            }
            else if (str[i] == ')'){
                if(st.empty()){
                    flag = 0;
                    break;
                }
                st.pop();
            }
        }
        if(flag){
            if(st.empty()){
                flag = 1;
            }
            else{
                flag = 0;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0; 
}


#endif

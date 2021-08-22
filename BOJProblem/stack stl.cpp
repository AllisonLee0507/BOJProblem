#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <stack>

using namespace std;

int main(void){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    
    if (st.empty() == true){
        cout << "empty stack" << endl;
    }
    return 0;
}
#endif

#if 0
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void){
    stack <int, vector<int>> st;
    
    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    
    if(st.empty() == true){
        cout << "empty stack" << endl;
    }
    return 0;
    
}
#endif

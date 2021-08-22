#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    (&v)->push_back(4);
    (&v)->push_back(5);
    (&v)->push_back(6);
    
    for(unsigned int i = 0; i < (&v)->size(); i++){
        cout << v[i] << endl;
    }
    
    return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    (&v)->push_back(4);
    (&v)->push_back(5);
    (&v)->push_back(6);
    
    vector<int>::iterator iter;
    for(iter = v.begin(); iter != v.end(); iter++){
        cout << *iter << endl;
    }
    
    return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    (&v)->push_back(4);
    (&v)->push_back(5);
    (&v)->push_back(6);
    
    vector<int>::iterator iter = v.begin();
    cout << *iter << endl;
    
    iter += 2;
    cout << *iter << endl;
    
    iter -= 1;
    cout << *iter << endl;
        
    return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    (&v)->push_back(4);
    (&v)->push_back(5);
    (&v)->push_back(6);
    
    vector<int>::iterator iter = v.begin();
    vector<int>::const_iterator citer = v.begin();
    
    cout << *iter << endl;
    cout << *citer << endl;
    
    cout << *(++iter) << endl;
    cout << *(++citer) << endl;
    
    *iter = 100;
        
    return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<int> v;
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    (&v)->push_back(14);
    (&v)->push_back(15);
    (&v)->push_back(16);
    
    vector<int>::iterator iter;
    iter = find(v.begin(), v.end(), 12);
    cout << *iter << endl;
    
    iter = find(v.begin(), v.end(), 10);
    
    if(iter == v.end()){
        cout << "검색 실패" << endl;
    }
    
    return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

int main(void){
    vector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    (&v)->push_back(2);
    (&v)->push_back(3);
    (&v)->push_back(6);
    
    sort(v.begin(), (&v)->end(), less<int>());
    
    vector<int>::iterator iter = v.begin();
    for(iter; iter!= v.end(); iter++){
        cout << *iter<< " ";
    }
    cout << endl;
    
    sort(v.begin(), v.end(), greater<int>());
    
    for(vector<int>::iterator iter = v.begin(); iter < v.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
    
    return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

int main(void){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    (&v)->push_back(4);
    (&v)->push_back(5);
    (&v)->push_back(6);
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    for(vector<int>::size_type i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    cout << typeid(vector<int>::size_type).name() << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    
    cout << v.max_size() << endl;
    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    vector<int> v;
    v.reserve(4);
    cout << "size: " << v.size() << " capacity : " << v.capacity() << endl;
    v.push_back(10);
    cout << "size: " << v.size() << " capacity : " << v.capacity() << endl;
    v.push_back(20);
    cout << "size: " << v.size() << " capacity : " << v.capacity() << endl;
    v.push_back(30);
    cout << "size: " << v.size() << " capacity : " << v.capacity() << endl;
    v.push_back(40);
    cout << "size: " << v.size() << " capacity : " << v.capacity() << endl;
    v.push_back(50);
    cout << "size: " << v.size() << " capacity : " << v.capacity() << endl;
    v.push_back(60);
    cout << "size: " << v.size() << " capacity : " << v.capacity() << endl;
    v.push_back(70);
    cout << "size: " << v.size() << " capacity : " << v.capacity() << endl;
    v.push_back(80);
    cout << "size: " << v.size() << " capacity : " << v.capacity() << endl;
    v.push_back(90);
    cout << "size: " << v.size() << " capacity : " << v.capacity() << endl;
    
    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    vector<int> v1(5);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    
    for(vector<int>::size_type i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    
    vector<int> v2(5);
    
    v2[0] = 10;
    v2[1] = 20;
    v2[2] = 30;
    v2[3] = 40;
    v2[4] = 50;
    
    for(vector<int>::size_type i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
    cout << endl;
    
    vector<int> v3(5);
    for(vector<int>::size_type i = 0; i < v3.size(); i++){
        cout << v3[i] << " ";
    }
    cout << endl;
    
    vector<int> v4(5,0);
    for(vector<int>::size_type i = 0; i < v4.size(); i++){
        cout << v4[i] << " ";
    }
    cout << endl;
    
    vector<int> v5(5,1);
    for(vector<int>::size_type i = 0; i < v5.size(); i++){
        cout << v5[i] << " ";
    }
    cout << endl;
    
    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    vector<int> v1(5);
    
    for(int i = 0; i < 5; i++){
        v1[i] = i + 1;
    }
    
    for(vector<int>::size_type i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    cout << "size: " << v1.size() << endl;
    cout << "capacity: " << v1.capacity() << endl;
    
    v1.resize(10);
    cout << "size: " << v1.size() << endl;
    cout << "capacity: " << v1.capacity() << endl;
    
    for(vector<int>::size_type i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    
    cout << endl;
    cout << "size: " << v1.size() << endl;
    cout << "capacity: " << v1. capacity() << endl;
    
    v1.resize(5);
    cout << "size: " << v1.size() << endl;
    cout << "capacity: " << v1.capacity() << endl;
    
    for(vector<int>::size_type i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    cout << "size: " << v1.size() << endl;
    cout << "capacity: " << v1.capacity() << endl;
    
    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    vector<int> v(5);
    for(int i = 0; i < v.size(); i++){
        v[i] = i + 1;
    }
    for(vector<int>::size_type i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    
    v.clear();
    cout << endl;
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    
    if(v.empty() == true){
        cout << "empty" << endl;
    }
    
    return 0;
}
#endif


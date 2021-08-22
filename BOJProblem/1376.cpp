#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>
#include <cassert>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAX = 100000;
typedef pair<int, int> P;

class SegTree{
public:
    void construct(int vn, vector<int> &v, vector<P> pos[]){
        cnt = v.size();
        size = 2;
        for(; size<cnt*2; size *= 2);
        A.resize(size);
        B.resize(cnt);
        
    }
}
#endif

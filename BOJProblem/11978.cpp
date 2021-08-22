#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pi;
const int INF = 987654321;
int main()
{
    int n;
    cin >> n;
    vector<pi> arr;
    int x = 0;
    int y = 0;
    arr.push_back(pi(0,0));
    while(n--)
    {
        char D;
        int S;
        cin >> D >> S;
        int dx = 0;
        int dy = 0;
        if(D == 'N')
        {
            dy = 1;
        }
        else if(D == 'S')
        {
            dy = -1;
        }
        else if(D == 'W')
        {
            dx = 1;
        }
        else
        {
            dx = -1;
        }
        for(int i = 0; i < S; i++)
        {
            x += dx;
            y += dy;
            arr.push_back(pi(x,y));
        }
    }
    int len = arr.size();
    int ans = INF;
    for(int i = 1; i <len; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i] == arr[j])
            {
                ans = min(ans, i-j);
            }
        }
    }
    cout << (ans == INF ? -1:ans);
}
#endif

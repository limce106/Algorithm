#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp{
    bool operator()(int a, int b)
    {
        if(abs(a) == abs(b))
        {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main()
{
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, cmp> pq;
    
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        
        if(x != 0)
        {
            pq.push(x);
        }
        else
        {
            if(pq.empty())
                cout << 0 << endl;
            else
            {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
    }
    
    return 0;
}
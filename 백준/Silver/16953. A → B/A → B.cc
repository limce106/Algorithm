#include <iostream>
#include <queue>
using namespace std;

long long a, b;

int main()
{
    cin >> a >> b;
    
    queue<pair<long long, int>> q;
    q.push({a, 1});
    
    while(!q.empty())
    {
        long long front = q.front().first;
        int curCnt = q.front().second;
        q.pop();
        
        if(front == b)
        {
            cout << curCnt << endl;
            return 0;
        }
        
        long long n = front * 2;
        if(n <= b)
            q.push({n, curCnt+1});
        
        long long m = front * 10 + 1;
        if(m <= b)
            q.push({m, curCnt+1});
    }
    
    cout << -1 << endl;
    
    return 0;
}
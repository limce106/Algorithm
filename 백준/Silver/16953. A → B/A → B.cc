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
        long long value = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if(value == b)
        {
            cout << dist;
            return 0;
        }
        
        long long n = value * 2;
        if(n <= b)
            q.push({n, dist+1});
        
        long long m = value * 10 + 1;
        if(m <= b)
            q.push({m, dist+1});
    }
    
    cout << -1;
    return 0;
}
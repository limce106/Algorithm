#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    int dx[2] = {-1, 1};
    bool visited[100001] = {false};
    visited[n] = true;
    
    queue<int> q;
    q.push(n);
    
    queue<int> distQ;
    distQ.push(0);
    
    int answer = 0;
    
    while(!q.empty())
    {
        int cur = q.front();
        int dist = distQ.front();
        q.pop();
        distQ.pop();
        
        if(cur == k)
        {
            answer = dist;
            break;
        }
        
        for(int i = 0; i < 3; i++)
        {
            int nx;
            
            if(i == 2)
            {
                nx = cur * 2;
            }
            else
            {
                nx = cur + dx[i];
            }
            
            if(nx < 0  || nx >= 100001)
                continue;
            if(visited[nx] == true)
                continue;
            
            visited[nx] = true;
            q.push(nx);
            distQ.push(dist+1);
        }
    }
    
    cout << answer;
    
    return 0;
}
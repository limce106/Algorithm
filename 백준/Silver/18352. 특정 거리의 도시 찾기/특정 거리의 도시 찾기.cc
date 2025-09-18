#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    
    vector<vector<int>> graph(n+1);
    int visited[300001];
    int start, end;
    
    for(int i = 0; i < m; i++)
    {
        cin >> start >> end;
        graph[start].push_back(end);
    }
    
    vector<int> result;
    queue<pair<int, int>> q;
    q.push({x, 0});
    visited[x] = 1;
    
    while(!q.empty())
    {
        int curNum = q.front().first;
        int curDepth = q.front().second;
        q.pop();
        
        if(curDepth == k)
        {
            result.push_back(curNum);
        }
        
        for(int i = 0; i < graph[curNum].size(); i++)
        {
            int nextNum = graph[curNum][i];
            if(!visited[nextNum])
            {
                q.push({nextNum, curDepth+1});
                visited[nextNum] = 1;
            }
        }
    }
    
    if(result.size() == 0)
    {
        cout << -1;
        return 0;
    }
    
    sort(result.begin(), result.end());
    for(auto r : result)
        cout << r << endl;
    
    return 0;
}
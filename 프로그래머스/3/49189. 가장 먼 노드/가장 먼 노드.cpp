#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n+1);
    
    for(int i = 0; i < edge.size(); i++)
    {
        int a=edge[i][0];
        int b=edge[i][1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    queue<pair<int, int>> q;
    q.push({1, 0});
    
    vector<int> dist(n+1, 0);
    
    vector<bool> visited(n+1, false);
    visited[1] = true;
    
    while(!q.empty())
    {
        int node = q.front().first;
        int curDist = q.front().second;
        q.pop();
        
        for(int i=0; i < graph[node].size(); i++)
        {
            if(visited[graph[node][i]])
                continue;
            
            visited[graph[node][i]] = true;
            q.push({graph[node][i], curDist+1});
            dist.push_back(curDist+1);
        }
    }

    int max = *max_element(dist.begin(), dist.end());
    answer = count(dist.begin(), dist.end(), max);
    
    return answer;
}
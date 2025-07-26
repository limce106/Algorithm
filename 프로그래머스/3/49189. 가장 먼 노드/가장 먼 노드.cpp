#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n+1);
    vector<int> dist(n+1,-1);
    
    for(int i = 0; i < edge.size(); i++)
    {
        int a = edge[i][0];
        int b = edge[i][1];   
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < graph[cur].size(); i++)
        {
            int node = graph[cur][i];
            if(dist[node] == -1)
            {
                dist[node] = dist[cur]+1;
                q.push(node);
            }
        }
    }
    
    auto maxDist = *max_element(dist.begin(), dist.end());
    answer = count(dist.begin(), dist.end(), maxDist);
    
    return answer;
}
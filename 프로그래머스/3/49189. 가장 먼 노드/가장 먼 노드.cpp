#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> v(n+1);
    
    for(int i = 0; i < edge.size(); i++)
    {
        int a = edge[i][0];
        int b = edge[i][1];
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    vector<bool> visited(n+1, false);
    visited[1] = true;
    
    queue<pair<int, int>> q;
    q.push({1, 0});
    
    vector<int> dist;
    
    while(!q.empty())
    {
        int front = q.front().first;
        int distance = q.front().second;
        q.pop();
        
        dist.push_back(distance);
        
        for(int i = 0; i < v[front].size(); i++)
        {
            if(visited[v[front][i]])
                continue;
            
            visited[v[front][i]] = true;
            q.push({v[front][i], distance+1});
        }
    }
    
    int maxValue = *max_element(dist.begin(), dist.end());
    int cnt = count(dist.begin(), dist.end(), maxValue);
    
    return cnt;
}
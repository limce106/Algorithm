#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> graph;
vector<vector<bool>> visited;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int maxHeight = 0;
int answer = 0;

void dfs(int x, int y, int curHeight)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if(visited[nx][ny])
            continue;
        if(graph[nx][ny] <= curHeight)
            continue;
        
        visited[nx][ny] = true;
        dfs(nx, ny, curHeight);
    }
}

int main()
{
    cin >> n;
    
    graph.resize(n, vector<int>(n, 0));
    visited.resize(n, vector<bool>(n, false));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
            maxHeight = max(maxHeight, graph[i][j]);
        }
    }
    
    for(int i = maxHeight - 1; i >= 0; i--)
    {
        visited.assign(n, vector<bool>(n, false));
        int count = 0;
        
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(graph[j][k] > i && !visited[j][k])
                {
                    count++;
                    dfs(j, k, i);
                }
            }
        }
        answer = max(answer, count);
    }
    
    cout << answer;
    
    return 0;
}
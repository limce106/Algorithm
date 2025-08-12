#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(graph[i][k] == 1 && graph[k][j] == 1)
                    graph[i][j] = 1;
            }
        }
    }
    
    int answer = 0;
    vector<bool> visited(n+1, false);
    
    for(int i = 1; i <= n; i++)
    {
        if(visited[i])
            continue;
        
        visited[i] = true;
        answer++;
        
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                continue;
            
            if(graph[i][j] == 1)
                visited[j] = true;
        }
    }
    
    cout << answer;
    
    return 0;
}
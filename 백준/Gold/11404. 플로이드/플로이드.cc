#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int n, m;

int main()
{
    cin >> n;
    cin >> m;
    
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    
    for(int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    
    for(int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        
        dist[start][end] = min(dist[start][end], cost);
    }
    
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dist[i][j] == INF)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
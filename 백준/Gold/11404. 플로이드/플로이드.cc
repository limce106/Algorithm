#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e9;

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    
    vector<vector<int>> graph(n+1, vector<int>(n+1, MAX));
    for(int i = 1; i <= n; i++)
    {
        graph[i][i] = 0;
    }
    
    int a, b, c;
    
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        
        graph[a][b] = min(graph[a][b], c);
    }
    
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {  
                if(graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(graph[i][j] == MAX)
                cout << 0 << " ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int x1, y1, x2, y2;
vector<vector<int>> graph;
vector<vector<int>> dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    graph.resize(n+1, vector<int>(n+1));
    dp.resize(n+1, vector<int>(n+1, 0));
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + graph[i][j];
        }
    }
    
    for(int i = 1; i <= m; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int result = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        cout << result << '\n'; 
    }
    
    return 0;
}
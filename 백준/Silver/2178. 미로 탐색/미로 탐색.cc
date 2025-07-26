#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> v(n,vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for(int j = 0; j < m; j++)
        {
            v[i][j] = row[j] - '0';
        }
    }
    
    queue<pair<int, int>> q;
    q.push({0,0});
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            
            if (v[nx][ny] == 1)
            {
                q.push({ nx,ny });
                v[nx][ny] = v[x][y] + 1;
            }
        }
    }
    
    cout << v[n-1][m-1];
    
    return 0;
}
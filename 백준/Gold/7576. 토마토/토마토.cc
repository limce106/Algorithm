#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main()
{
    int n, m;
    cin >> m >> n;
    
    vector<vector<int>> v(n, vector<int>(m));
    queue<pair<int, int>> q;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            
            if(v[i][j] == 1)
            {
                q.push({i,j});
            }
        }
    }
    
    int days = -1;
    int size = q.size();
    
    while(!q.empty())
    {
        int curSize = q.size();
        days++;
        
        for(int i = 0; i < curSize; i++)
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
                
                if(v[nx][ny] == 0)
                {
                    v[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }      
    }
    
    // 안 익은 토마토 있는지 검사
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(v[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }
    
    cout << days;
    
    return 0;
}
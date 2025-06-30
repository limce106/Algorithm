#include<vector>
#include <queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<bool>> visited;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    visited.resize(n, vector<bool>(m, false));
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    
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
            
            if(visited[nx][ny] || maps[nx][ny] == 0)
                continue;
            
            q.push({nx, ny});
            maps[nx][ny] = maps[x][y] + 1;
            visited[nx][ny] = true;
        }
    }
    
    int answer = 0;
    
    if(maps[n - 1][m - 1] == 1)
    {
        answer = -1;
    }
    else
    {
        answer = maps[n - 1][m - 1];
    }
    
    return answer;
}
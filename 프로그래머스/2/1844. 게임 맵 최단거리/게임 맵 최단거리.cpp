#include<vector>
#include<queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> visit;
    
    n = maps.size();
    m = maps[0].size();
    
    visit.resize(n, vector<bool>(m, false));
    
    q.push({0, 0});
    visit[0][0] = true;
    
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
            
            if(visit[nx][ny] || maps[nx][ny] == 0)
                continue;
            
            q.push({nx, ny});
            visit[nx][ny] = true;
            maps[nx][ny] = maps[x][y] + 1;
        }
    }
    
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

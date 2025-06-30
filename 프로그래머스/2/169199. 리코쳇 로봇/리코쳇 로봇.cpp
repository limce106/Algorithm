#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<vector<bool>> visited;

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();
    visited.resize(n, vector<bool>(m, false));
    
    queue<pair<pair<int, int>, int>> q;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'R')
            {
                q.push({{i, j}, 1});
                visited[i][j] = true;
                break;
            }
        }
    }
    
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int count = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x;
            int ny = y;
            
            while(true)
            {                
                nx += dx[i];
                ny += dy[i];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 'D')
                {
                    nx -= dx[i];
                    ny -= dy[i];
                    break;
                }
            }
            
            if(board[nx][ny] == 'G')
                return count;
            
            if(visited[nx][ny])
                continue;
            
            visited[nx][ny] = true;
            q.push({{nx, ny}, count + 1});
        }
    }
    
    return -1;
}
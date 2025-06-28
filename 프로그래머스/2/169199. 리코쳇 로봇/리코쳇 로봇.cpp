#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<bool>> visit;

int solution(vector<string> board) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    
    visit.resize(n, vector<bool>(m, false));
    
    queue<pair<pair<int, int>, int>> q;
    int find = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'R')
            {
                q.push({{i, j}, 0});
                visit[i][j] = true;
                find = true;
                break;
            }
        }
        if(find)
            break;
    }
    
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int depth = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x;
            int ny = y;
            answer++;
            
            while(true)
            {
                int tx = nx + dx[i];
                int ty = ny + dy[i];

                if(tx < 0 || tx >= n || ty < 0 || ty >= m)
                    break;
                if(board[tx][ty] == 'D')
                    break;
                
                nx = tx;
                ny = ty;
            }
            
            if(visit[nx][ny])
                continue;
            if(board[nx][ny] == 'G')
            {
                return depth + 1;
            }
            
            q.push({{nx, ny}, depth + 1});
            visit[nx][ny] = true;
        }
    }

    return -1;
}
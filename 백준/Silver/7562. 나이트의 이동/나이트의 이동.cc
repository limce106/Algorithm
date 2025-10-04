#include <iostream>
#include <queue>
using namespace std;

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    int test;
    cin >> test;
    
    while(test--)
    {
        int l; // 체스판 크기
        cin >> l;
        
        int curX, curY; // 현재 있는 칸
        cin >> curX >> curY;
        
        int targetX, targetY; // 이동하려는 칸
        cin >> targetX >> targetY;
        
        queue<pair<int, int>> q;
        q.push({curX, curY});
        
        vector<vector<bool>> visited(l, vector<bool>(l, false));
        visited[curX][curY] = true;
        
        vector<vector<int>> count(l, vector<int>(l, 0));
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(x == targetX && y == targetY)
            {
                cout << count[x][y] << endl;
                break;
            }
            
            for(int i = 0; i < 8; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || nx >= l || ny < 0 || ny >= l)
                    continue;
                
                if(visited[nx][ny])
                    continue;
                
                visited[nx][ny] = true;
                count[nx][ny] = count[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return 0;
}
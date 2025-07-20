#include <string>
#include <vector>
#include <queue>

using namespace std;

bool map[102][102];
bool visited[102][102];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 2배 확대
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    // 전체 경로 그리기
    for(int i = 0; i < rectangle.size(); i++)
    {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for(int x = x1; x <= x2; x++)
        {
            for(int y = y1; y <= y2; y++)
            {
                map[x][y] = true;
            }
        }
    }
    
    // 테두리만 남기고 내부 채움 제거
    for(int i = 0; i < rectangle.size(); i++)
    {
        int x1 = rectangle[i][0] * 2 + 1;
        int y1 = rectangle[i][1] * 2 + 1;
        int x2 = rectangle[i][2] * 2 - 1;
        int y2 = rectangle[i][3] * 2 - 1;
        
        for(int x = x1; x <= x2; x++)
        {
            for(int y = y1; y <= y2; y++)
            {
                map[x][y] = false;
            }
        }
    }
    
    // 외곽 따라 BFS
    queue<pair<int, int>> q;
    queue<int> distQ;
    
    q.push({characterX, characterY});
    visited[characterX][characterY] = true;
    distQ.push(0);
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        int dist = distQ.front();
        distQ.pop();
        
        if(x == itemX && y == itemY)
        {
            return dist/2;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= 102 || ny < 0 || ny >= 102)
                continue;
            if(visited[nx][ny])
                continue;
            if(!map[nx][ny])
                continue;
            
            visited[nx][ny] = true;
            q.push({nx, ny});
            distQ.push(dist+1);
        }
    }
    
    return 0;
}
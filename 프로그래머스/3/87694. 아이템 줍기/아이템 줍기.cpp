#include <string>
#include <vector>
#include <queue>

using namespace std;

bool map[102][102] = {false};
bool visited[102][102] = {false};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    for(int i = 0; i < rectangle.size(); i++)
    {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for(int i = x1; i <= x2; i++)
        {
            for(int j = y1; j <= y2; j++)
            {
                map[i][j] = true;
            }
        }
    }
    
    for(int i = 0; i < rectangle.size(); i++)
    {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for(int i = x1 + 1; i <= x2 - 1; i++)
        {
            for(int j = y1 + 1; j <= y2 - 1; j++)
            {
                map[i][j] = false;
            }
        }
    }
    
    queue<pair<int, int>> q;
    queue<int> distQ;
    
    q.push({characterX, characterY});
    visited[characterX][characterY] = true;
    distQ.push(0);
    
    while(true)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        int dist = distQ.front();
        distQ.pop();
        
        if(x == itemX && y == itemY)
            return dist/2;
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!map[nx][ny] || visited[nx][ny])
                continue;
            
            if(nx < 0 || nx >= 102 || ny < 0 || ny >= 102)
                continue;
            
            q.push({nx, ny});
            visited[nx][ny] = true;
            distQ.push(dist+1);
        }
    }
    
    return 0;
}
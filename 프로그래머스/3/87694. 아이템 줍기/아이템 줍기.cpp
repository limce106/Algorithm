#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    bool map[102][102] = {false};
    
    for(auto& r : rectangle)
    {
        int x1 = r[0] * 2;
        int y1 = r[1] * 2;
        int x2 = r[2] * 2;
        int y2 = r[3] * 2;
        
        for(int i = x1; i <= x2; i++)
        {
            for(int j = y1; j <= y2; j++)
            {
                map[i][j] = true;
            }
        }
    }
    
    for(auto& r : rectangle)
    {
        int x1 = r[0] * 2 + 1;
        int y1 = r[1] * 2 + 1;
        int x2 = r[2] * 2 - 1;
        int y2 = r[3] * 2 - 1;
        
        for(int i = x1; i <= x2; i++)
        {
            for(int j = y1; j <= y2; j++)
            {
                map[i][j] = false;
            }
        }
    }
    
    queue<pair<int, int>> q;
    queue<int> distQ;
    
    q.push({characterX, characterY});
    distQ.push(0);
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int dist = distQ.front();
        q.pop();
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
            if(map[nx][ny] == false)
                continue;
            
            map[nx][ny] = false;
            q.push({nx, ny});
            distQ.push(dist+1);
        }
    }
    
    return 0;
}
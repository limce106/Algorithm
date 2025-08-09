#include <iostream>
#include <vector>
using namespace std;

int dx[8] = {-1,1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int h, w, l;
vector<string> grid;
string target;
long long answer = 0;
vector<vector<vector<long long>>> dp; // -1: 미방문, 0 이상: 계산된 값

long long dfs(int x, int y, int count)
{   
    if(count == l)
    {
        return 1;
    }
    
    // dp[x][y][count]는 (x, y) 위치에서 target의 count번째 문자부터 끝까지 만들 수 있는 경우의 수
    long long& ret = dp[x][y][count];
    if(ret != -1)
        return ret;
    
    ret = 0;
        
    for(int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= h || ny < 0 || ny >= w)
            continue;
        
        if(target[count] != grid[nx][ny])
            continue;
       
        ret += dfs(nx, ny, count+1);
    }
    
    return ret;
}

int main()
{
    cin >> h >> w >> l;
    
    grid.resize(h);
    for(int i = 0; i < h; i++)
    {
        cin >> grid[i];
    }
    
    cin >> target;
    
    dp.assign(h, vector<vector<long long>>(w, vector<long long>(l, -1)));
    
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(grid[i][j] == target[0])
                answer += dfs(i, j, 1);
        }
    }
    
    cout << answer;
    
    return 0;
}
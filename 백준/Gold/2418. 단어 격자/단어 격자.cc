#include <iostream>
#include <vector>
using namespace std;

int h, w, l;
vector<string> graph;
string target;
vector<vector<vector<long long>>> dp;

long long answer = 0;

int dx[8] ={-1,1,0,0,1,1,-1,-1};
int dy[8] ={0,0,-1,1,1,-1,1,-1};

long long dfs(int x, int y, int cnt)
{
    if(cnt == target.size())
        return 1;
    
    long long& ret = dp[x][y][cnt];
    if(ret > 0)
        return ret;
    
    ret = 0;
    
    for(int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= h || ny < 0 || ny >=w)
            continue;
        
        if(graph[nx][ny] == target[cnt])
        {
            ret += dfs(nx, ny, cnt+1);
        }
    }
    
    return ret;
}

int main()
{
    cin >> h >> w >> l;
    
    graph.resize(h);
    dp.resize(h, vector<vector<long long>>(w, vector<long long>(l, -1)));
    
    for(int i = 0; i < h; i++)
    {
        cin >> graph[i];
    }
    
    cin >> target;
    
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(target[0] == graph[i][j])
                answer += dfs(i, j, 1);
        }
    }
    
    cout << answer;
    
    return 0;
}
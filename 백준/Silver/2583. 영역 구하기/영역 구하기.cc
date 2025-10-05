#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k;
vector<vector<int>> graph;
vector<vector<bool>> visited;
vector<int> answer;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void SetVisited(int x1, int y1, int x2, int y2)
{
    for(int i = x1; i < x2; i++)
    {
        for(int j = y1; j < y2; j++)
        {
            visited[i][j] = true;
        }
    }
}

int dfs(int x, int y)
{    
    visited[x][y] = true;
    int count = 1;
    
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        
        if(visited[nx][ny])
            continue;
        
        count += dfs(nx,ny);
    }
    
    return count;
}

int main()
{
    cin >> m >> n >> k;
    
    graph.resize(m, vector<int>(n, 0));
    visited.resize(m, vector<bool>(n, false));
    
    for(int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        
        SetVisited(x1, y1, x2, y2);
    }
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
                answer.push_back(dfs(i, j));
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    
    return 0;
}
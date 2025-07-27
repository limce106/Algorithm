#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

vector<vector<bool>> visited;

int dfs(vector<vector<int>>& v, int& n, int x, int y)
{
    visited[x][y] = true;
    int cnt = 1;
    
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if(visited[nx][ny])
            continue;
        if(v[nx][ny] == 0)
            continue;
        
        cnt += dfs(v, n, nx, ny);
    }
    
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    
    vector<vector<int>> v(n, vector<int>(n,0));
    visited.resize(n, vector<bool>(n,false));
    
    vector<int> answer;
    
    for(int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        
        for(int j = 0; j < n; j++)
        {
            v[i][j] = row[j] - '0';
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(v[i][j] == 1 && !visited[i][j])
            {
                 answer.push_back(dfs(v, n, i, j));   
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
    
    return 0;
}
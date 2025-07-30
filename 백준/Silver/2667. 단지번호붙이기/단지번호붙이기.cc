#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int n;
vector<vector<int>> v;
vector<vector<bool>> visited;
vector<int> answer;

int dfs(vector<vector<int>>& v, int x, int y, int count)
{
    visited[x][y] = true;
    
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if(visited[nx][ny] || v[nx][ny] == 0)
            continue;
        
        count += dfs(v, nx, ny, 1);
    }
    
    return count;
}

int main()
{
    cin >> n;
    
    v.resize(n, vector<int>(n,0));
    visited.resize(n,vector<bool>(n, false));
    
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
            if(!visited[i][j] && v[i][j] == 1)
            {
                answer.push_back(dfs(v, i, j , 1));
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
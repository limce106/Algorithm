#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int dfs(vector<vector<int>>& grid, vector<int>& visited, int node)
{
    visited[node] = true;
    int count = 1;
    
    for(int i = 0; i < grid[node].size(); i++)
    {        
        if(!visited[grid[node][i]])
            count += dfs(grid, visited, grid[node][i]);
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for(int i = 0; i < wires.size(); i++)
    {
        vector<vector<int>> grid(n + 1);
        for(int j = 0; j < wires.size(); j++)
        {
            if(i == j)
                continue;
            
            int a = wires[j][0];
            int b = wires[j][1];
            
            grid[a].push_back(b);
            grid[b].push_back(a);
        }
        
        vector<int> visited(n + 1);
        int part = dfs(grid, visited, 1);
        int diff = part - (n - part);
        answer = min(answer, abs(diff));
    }
    
    return answer;
}
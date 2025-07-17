#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

void dfs(vector<vector<int>>& computers, int computer)
{
    visited[computer] = true;
    
    for(int i = 0; i < computers.size(); i++)
    {
        if(i == computer)
            continue;
        
        if(visited[i])
            continue;
        
        if(computers[computer][i] == 0)
            continue;
            
        dfs(computers, i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.resize(n, false);
    
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(computers, i);
            answer++;
        }
    }
    
    return answer;
}
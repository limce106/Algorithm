#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<bool> visited;

bool dfs(string cur, vector<vector<string>>& tickets, vector<string>& answer)
{
    answer.push_back(cur);
    
    if(tickets.size() + 1 == answer.size())
        return true;
    
    for(int i = 0; i < tickets.size(); i++)
    {
        if(tickets[i][0] == cur && !visited[i])
        {
            visited[i] = true;
            if(dfs(tickets[i][1], tickets, answer))
                return true;
            
            visited[i] = false;
            answer.pop_back();
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    visited.resize(tickets.size(), false);
    
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, answer);
    
    return answer;
}
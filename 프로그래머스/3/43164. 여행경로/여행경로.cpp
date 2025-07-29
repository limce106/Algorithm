#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;

bool dfs(vector<vector<string>>& tickets, vector<string>& answer, string curAirport)
{
    answer.push_back(curAirport);
    
    if(tickets.size() + 1 == answer.size())
        return true;
    
    for(int i = 0; i < tickets.size(); i++)
    {
        if(visited[i])
            continue;
        
        if(tickets[i][0] == curAirport)
        {         
            visited[i] = true;
            
            if(dfs(tickets, answer, tickets[i][1]))
            {
                return true;
            }
            
            visited[i] = false;
            answer.pop_back();
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    visited.resize(tickets.size());
    
    sort(tickets.begin(), tickets.end());
    dfs(tickets, answer, "ICN");
    return answer;
}
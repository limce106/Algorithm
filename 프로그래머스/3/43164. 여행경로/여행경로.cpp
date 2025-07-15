#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;

bool dfs(vector<vector<string>>& tickets, string curAirport, vector<string>& answer)
{
    answer.push_back(curAirport);
    
    if(answer.size() == tickets.size() + 1)
        return true;
    
    for(int i = 0; i < tickets.size(); i++)
    {
        if(visited[i])
            continue;
        
        if(tickets[i][0] == curAirport)
        {
            visited[i] = true;
            
            if(dfs(tickets, tickets[i][1], answer))
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
    dfs(tickets, "ICN", answer);
    visited[0] = true;
    
    return answer;
}
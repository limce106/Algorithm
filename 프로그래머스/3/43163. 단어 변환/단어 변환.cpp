#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;
int answer = 50;

bool check(string a, string b)
{
    int count = 0;
    
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i])
            count++;
    }
    
    if(count == 1)
        return true;
    else
        return false;
}

void dfs(string cur, string& target, vector<string>& words, int count)
{
    if(cur == target)
    {
        answer = min(answer, count);
        return;
    }
    
    for(int i = 0; i < words.size(); i++)
    {
        if(visited[i])
            continue;
        
        if(check(cur, words[i]))
        {
            visited[i] = true;
            dfs(words[i], target, words, count+1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    visited.resize(words.size());
    
    dfs(begin, target, words, 0);
    
    if(answer == 50)
        return 0;
    
    return answer;
}
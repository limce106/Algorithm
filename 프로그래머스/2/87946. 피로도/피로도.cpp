#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = -1;
int visit[8];

void dfs(int count, int curK, vector<vector<int>>& dungeons)
{
    for(int i = 0; i < dungeons.size(); i++)
    {
        if(visit[i] || dungeons[i][0] > curK)
            continue;
        
        visit[i] = true;
        dfs(count + 1, curK - dungeons[i][1], dungeons);
        visit[i] = false;
    }
    answer = max(answer, count);
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons);
    
    return answer;
}
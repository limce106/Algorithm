#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> graph(n+1, vector<int>(n+1,0));
    
    for(auto r : results)
    {
        int win = r[0];
        int lose = r[1];
        
        graph[win][lose] = 1;
        graph[lose][win] = -1;
    }
    
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(graph[i][k] == 1 && graph[k][j] == 1)
                    graph[i][j] = 1;
                else if(graph[i][k] == -1 && graph[k][j] == -1)
                    graph[i][j] = -1;
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                continue;
            
            if(graph[i][j] != 0)
                cnt++;
        }
        
        // 자기 자신을 제외한 나머지 선수들과의 승패를 모두 알고 있다면
        if(cnt == n - 1)
            answer++;
    }
    
    return answer;
}
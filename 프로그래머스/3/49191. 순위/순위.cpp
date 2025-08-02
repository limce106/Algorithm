#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> v(n+1, vector<int>(n+1, 0));
    
    for(auto r : results)
    {
        int win = r[0];
        int lose = r[1];
        
        v[win][lose] = 1;
        v[lose][win] = -1;
    }
    
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(v[i][k] == 1 && v[k][j] == 1)
                    v[i][j] =  1;
                else if(v[i][k] == -1 && v[k][j] == -1)
                    v[i][j] =  -1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                continue;
            
            if(v[i][j] != 0)
                cnt++;
        }
        
        if(cnt == n-1)
            answer++;
    }
    
    return answer;
}
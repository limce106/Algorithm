#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> num(n);
int op[4];
int max_result = -1e9;
int min_result = 1e9;

void dfs(int idx, int current)
{
    if(idx == n)
    {
        max_result = max(max_result, current);
        min_result = min(min_result, current);
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        // 개수가 있으면
        if(op[i] > 0)
        {
            op[i]--;
            
            if(i == 0)
                dfs(idx + 1, current + num[idx]);
            else if (i == 1)
                dfs(idx + 1, current - num[idx]);
            else if (i == 2)
                dfs(idx + 1, current * num[idx]);
            else
            {
                if(current < 0)
                    dfs(idx + 1, -(-current / num[idx]));
                else
                    dfs(idx + 1, (current / num[idx]));
            }
            
            op[i]++;
        }
    }
}

int main()
{
    cin >> n;
    
    num.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    
    for(int i = 0; i < 4; i++)
    {
        cin >> op[i];
    }
    
    dfs(1, num[0]);
        
    cout << max_result << '\n' << min_result << '\n';
    
    return 0;
}
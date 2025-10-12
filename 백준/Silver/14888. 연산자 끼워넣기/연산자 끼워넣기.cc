#include <iostream>
#include <vector>
using namespace std;

int n;
int maxAnswer = -1e9;
int minAnswer = 1e9;
vector<int> v;
int op[4];

void dfs(int idx, int current)
{
    if(idx == n)
    {
        maxAnswer = max(maxAnswer, current);
        minAnswer = min(minAnswer, current);
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        if(op[i] > 0)
        {
            op[i]--;
            
            if(i == 0)
                dfs(idx+1, current+v[idx]);
            else if(i == 1)
                dfs(idx+1, current-v[idx]);
            else if(i == 2)
                dfs(idx+1, current * v[idx]);
            else
            {
                if(current < 0)
                    dfs(idx+1, -(-current / v[idx]));
                else
                    dfs(idx+1, current/v[idx]);
            }
            
            op[i]++;
        }
    }
}

int main()
{
    cin >> n;
    v.resize(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    for(int i = 0; i < 4; i++)
    {
        cin >> op[i];
    }
    
    dfs(1, v[0]);
    
    cout << maxAnswer << endl << minAnswer << endl;
    
    return 0;
}
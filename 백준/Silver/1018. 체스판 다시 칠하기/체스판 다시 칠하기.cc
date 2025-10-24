#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> board(n, vector<char>(m,0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    
    int ans = 64;
    
    for (int x = 0; x <= n - 8; x++) 
    {
        for (int y = 0; y <= m - 8; y++)
        {
            int cntB = 0;
            int cntW = 0;
            
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    char cur = board[x + i][y + j];
                    
                    if ((i + j) % 2 == 0)
                    {
                        if (cur != 'W') cntB++;
                        if (cur != 'B') cntW++;
                    }
                    else
                    {
                        if (cur != 'B') cntB++;
                        if (cur != 'W') cntW++;
                    }
                }
            }
            ans = min(ans, min(cntB, cntW));
        }
    }
    
    cout << ans;
    
    return 0;
}
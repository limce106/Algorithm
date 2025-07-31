#include <iostream>
#include <vector>
using namespace std;

int white = 0;
int blue = 0;

void solve(vector<vector<int>>& v, int x, int y, int size)
{
    bool same = true;
    int color = v[x][y];
    
    for(int i = x; i < x+size; i++)
    {
        for(int j = y; j < y+size; j++)
        {
            if(color != v[i][j])
            {
                same = false;
                break;
            }
        }
        
        if(!same)
            break;
    }
    
    if(same)
    {
        if(color == 0)
            white++;
        else
            blue++;
    }
    else
    {
        int half = size/2;
        solve(v, x, y, half);
        solve(v, x+half, y, half);
        solve(v, x, y+half, half);
        solve(v, x+half, y+half, half);
    }
}

int main()
{
    int n;
    cin >> n;
    
    vector<vector<int>> v(n, vector<int>(n,0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    
    solve(v, 0, 0, n);
    
    cout << white << endl;
    cout << blue << endl;
    
    return 0;
}
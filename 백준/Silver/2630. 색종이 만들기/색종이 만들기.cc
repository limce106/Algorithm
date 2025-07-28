#include <iostream>
#include <vector>

using namespace std;

int white = 0, blue = 0;

void divide(const vector<vector<int>>& paper, int x, int y, int size)
{
    int color = paper[x][y];
    bool same = true;
    
    for(int i = x; i < x + size; i++)
    {
        for(int j = y; j < y + size; j++)
        {
            if(paper[i][j] != color)
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
        divide(paper, x , y, half);
        divide(paper, x , y+half, half);
        divide(paper, x+half , y, half);
        divide(paper, x+half , y+half, half);
    }
}

int main()
{
    int n;
    cin >> n;
    
    vector<vector<int>> paper(n,vector<int>(n));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> paper[i][j];
        }
    }
    
    divide(paper, 0, 0, n);
    
    cout << white << endl;
    cout << blue << endl;
    
    return 0;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxValue = 0;

void dp(vector<vector<int>>& triangle, int x, vector<vector<int>>& temp)
{
    for(int i = 0; i <= x; i++)
    {
        int m = max(temp[x+1][i]+triangle[x][i], temp[x+1][i+1]+triangle[x][i]);
        temp[x].push_back(m);
    }
    
    if(x == 0)
    {
        maxValue = temp[x][0];
        return;
    }
    
    dp(triangle, x - 1, temp);
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> temp(triangle.size());
    for(int i = 0; i < triangle.size(); i++)
    {
        temp[triangle.size()-1].push_back(triangle[triangle.size()-1][i]);
    }
    
    dp(triangle, triangle.size()-2, temp);
    answer = maxValue;
    return answer;
}
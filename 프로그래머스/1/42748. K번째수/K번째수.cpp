#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int n = 0; n < commands.size(); n++)
    {
        vector<int> temp;
        int i = commands[n][0];
        int j = commands[n][1];
        int k = commands[n][2];
        
        for(int m = 0; m < array.size(); m++)
        {
            if(m >= i - 1 && m <= j - 1)
            {
                temp.push_back(array[m]);
            }
        }
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k - 1]);
    }
    
    return answer;
}
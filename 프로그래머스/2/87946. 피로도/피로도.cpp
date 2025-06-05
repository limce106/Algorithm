#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<int> v;
    for(int i = 0; i < dungeons.size(); i++)
    {
        v.push_back(i);
    }
    
    int max = 0;
    do{
        int temp = 0;
        int curK = k;
        for(int i = 0; i < v.size(); i++)
        {
            int index = v[i];
            if(curK >= dungeons[index][0])
            {
                curK -= dungeons[index][1];
                temp++;
            }
        }
        max = max >= temp ? max : temp;
    }while(next_permutation(v.begin(), v.end()));
    
    answer = max;
    
    return answer;
}
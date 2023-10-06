#include <string>
#include <vector>

using namespace std;

int count = 0;

int count_x(int x)
{
    for(int i = 1; i <= x; i++)
    {
        if(x%i == 0)
            count++;
    }
    return count;
}

int solution(int left, int right) {
    int answer = 0;
    vector<int> Numbers;
    
    for(int i = left; i <= right; i++)
    {
        count_x(i);
        
        if(count % 2 != 0)
        {
            Numbers.push_back(i*(-1));
        }
        else
            Numbers.push_back(i);
        
        count = 0;
    }
    
    for(int i = 0; i < Numbers.size(); i++)
        answer += Numbers[i];
    
    return answer;
}
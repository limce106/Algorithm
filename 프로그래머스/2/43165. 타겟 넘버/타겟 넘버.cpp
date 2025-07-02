#include <string>
#include <vector>

using namespace std;

int count = 0;

void dfs(vector<int>& numbers, int& target, int idx, int curNum)
{
    if(idx == numbers.size())
    {
        if(curNum == target)
        {
            count++;
        }
        return;
    }
    
    dfs(numbers, target, idx + 1, curNum + numbers[idx]);
    dfs(numbers, target, idx + 1, curNum - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0);
    answer = count;
    return answer;
}
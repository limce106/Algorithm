#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i = 0; i < numbers.size()-1; i++)
    {
        for(int j = 1; j < numbers.size(); j++)
        {
            if(i != j)
            {
                answer.push_back(numbers[i]+numbers[j]);
            }
        }
    }
    sort(answer.begin(), answer.end(), less<>());
    answer.erase(unique(answer.begin(), answer.end()),answer.end());
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string& a, string& b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> nums;
    for(auto n : numbers)
    {
        nums.push_back(to_string(n));
    }
    
    sort(nums.begin(), nums.end(), compare);
    
    for(string n : nums)
    {
        answer += n;
    }
    
    if (nums[0] == "0")
        return "0";
    
    return answer;
}
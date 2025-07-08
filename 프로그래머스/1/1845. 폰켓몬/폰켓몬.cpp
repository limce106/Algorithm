#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> m;    // 번호, 수
    
    for(int n : nums)
    {
        m[n]++;
    }
    
    if(m.size() > nums.size() / 2)
    {
        answer = nums.size() / 2;
    }
    else
    {
        answer = m.size();
    }
    
    return answer;
}
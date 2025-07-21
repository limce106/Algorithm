#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long left = 1;
    long long right = n * (long long)times.back();
    
    while(left <= right)
    {
        long long mid = (left+right)/2;
        long long passed = 0;
        
        // 현재 시간 기준으로 심사위원들이 몇 명을 처리했는지
        for(int i = 0; i < times.size(); i++)
        {
            passed += (mid / (long long) times[i]);
        }
        
        // 현재 값보다 많은 사람을 처리할 수 있을 경우
        if(passed >= n)
        {
            right = mid - 1;
            answer = mid;
        }
        // 현재 값보다 적은 사람을 처리할 수 있을 경우
        else
            left = mid + 1;
    }
    
    return answer;
}
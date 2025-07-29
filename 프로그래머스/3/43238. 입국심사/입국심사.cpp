#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long start = 1;
    long long end = (long long)times.back() * n;
    
    while(start <= end)
    {
        long long mid = (start + end)/2;
        
        long long people = 0;
        for(int i = 0; i < times.size(); i++)
        {
            people += (long long)mid/times[i];
        }
        
        if(people >= n)
        {
            answer = mid;
            end = mid - 1;
        }
        else
        {
            start = mid  + 1;
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    
    int n = food_times.size();
    long long sum = 0;
    vector<pair<int, int>> foods;  // pair<먹는 시간, 음식 번호>
    
    for(int i = 0; i < n; i++)
    {
        sum += food_times[i];
        foods.push_back({food_times[i], i+1});
    }
    
    if(sum <= k)
    {
        return -1;
    }
    
    // 시간 기준 오름차순 정렬
    sort(foods.begin(), foods.end());
    
    long long prev_time = 0; // 이전 단계에서 제거한 음식의 시간
    for(int i = 0; i < n; i++)
    {
        long long cur_time = foods[i].first;
        long long gap = cur_time - prev_time;
        if(gap == 0) continue;
        
        long long spend = gap * (n - i);
        if(spend <= k)
        {
            k -= spend;
            prev_time = cur_time;
        }
        else
        {
            vector<pair<int, int>> remain;
            for(int j = i; j < n; j++)
            {
                remain.push_back({foods[j].second, foods[j].first});
            }
            sort(remain.begin(), remain.end()); // 음식 번호 기준
            
            int idx = k % remain.size();
            return remain[idx].first;
        }
    }
    
    
    return answer;
}
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
        long long cur_time = foods[i].first; // 현재 가장 짧은 시간
        // 먹고 남은 시간
        long long gap = cur_time - prev_time;
        if(gap == 0) continue;
        
        // 남아있는 음식의 개수만큼 한 바퀴를 돌아서 해당 음식을 0으로 만드는데 필요한 총 시간
        long long spend = gap * (n - i);
        // 현재 처리 중인 음식을 다 먹을 수 있는 경우
        if(spend <= k)
        {
            k -= spend;
            prev_time = cur_time; // 이번에 다 먹은 음식의 시간을 기록
        }
        // 현재 음식을 다 먹기 전에 네트워크 장애 발생
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
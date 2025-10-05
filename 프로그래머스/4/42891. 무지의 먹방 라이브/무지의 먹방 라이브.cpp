#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long total = 0;
    
    vector<pair<int, int>> foods;
    int n = food_times.size();
    
    for(int i = 0; i < n; i++)
    {
        total += food_times[i];
        foods.push_back({food_times[i], i+1});
    }
    
    if(total <= k)
        return -1;
    
    sort(foods.begin(), foods.end());
    
    long long prev_time = 0;
    for(int i = 0; i < n; i++)
    {
        long long cur_time = foods[i].first;
        long long gap = cur_time - prev_time;
        if(gap == 0) continue;
        
        long long remain = gap * (n-i);
        if(remain <= k)
        {
            k -= remain;
            prev_time = cur_time;
        }
        else
        {
            vector<pair<int, int>> remain;
            for(int j = i; j < n; j++)
            {
                remain.push_back({foods[j].second, foods[j].first});
            }
            sort(remain.begin(), remain.end());
                
            return remain[k % remain.size()].first;
        }
    }
    
    return answer;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    // 종료 시간이 같으면 시작 시간이 빠른 순서로 정렬
    if(a.second == b.second)
        return a.first < b.first;
    
    // 종료 시간이 빠른 순서대로 정렬
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    
    vector<pair<int, int>> meetings(n);
    for(int i = 0; i < n; i++)
    {
        cin >> meetings[i].first >> meetings[i].second;
    }
    
    sort(meetings.begin(), meetings.end(), compare);
    
    int count = 0;
    int endTime = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(meetings[i].first >= endTime)
        {
            endTime = meetings[i].second;
            count++;
        }
    }
    
    cout << count;
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int MAX = 10001;
    
    int n, d;
    cin >> n >> d;
    
    vector<int> map(d+1, MAX); // 고속도로 i 지점까지 가는 최소 거리
    vector<pair<int, int>> sc[MAX]; // 크기가 MAX인 배열, 각 원소가 vector<pair<int,int>>
    int from, to, dis;
    
    for(int i = 0; i < n; i++)
    {
        cin >> from >> to >> dis;
        sc[to].push_back({from, dis});
    }
    
    map[0] = 0;
    for(int i = 1; i <= d; i++)
    {
        if(sc[i].size() == 0)
            map[i] = map[i-1] + 1;
        else
        {
            for(auto value : sc[i])
            {
                // map[i], map[i-1] + 1, 이전 지름길 + 거리
                map[i] = min(map[i], min(map[i-1] + 1, map[value.first] + value.second));
            }
        }
    }
    
    cout << map[d];
    
    return 0;
}
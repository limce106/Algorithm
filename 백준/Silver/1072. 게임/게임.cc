#include <iostream>
using namespace std;

long long x, y;
long long ans = 0;
int curZ = 0;

void binary_research()
{
    long long start = 1;
    long long end = 1000000000;
    long long mid = 0;
    
    while(start <= end)
    {
        mid = (start + end) / 2;
        long long tempZ = (y + mid) * 100 / (x + mid);
        
        if(tempZ > curZ)
        {
            end = mid - 1;
            ans = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
}

int main()
{
    cin >> x >> y;
    
    curZ = y * 100 / x;

    // 승률이 99%이면 최대 99.999..% 이기 때문에 절대 99% 이상은 못 넘김 (소수점을 버리기 때문)
    if(curZ >= 99)
    {
        cout << -1;
        return 0;
    }
    
    binary_research();
    cout << ans;
    
    return 0;
}
// int의 범위는 ±21억 -> int 범위를 넘을 수 있기 때문에 long long 사용

// 시간 복잡도: O(log N)
// 이진 탐색: O(log N), tempZ: O(1)

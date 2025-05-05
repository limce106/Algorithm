#include <iostream>
using namespace std;

long long x, y;
int ans = 0;
int curZ = 0;

void binary_research()
{
    int start = 1;
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
    
    if(curZ >= 99)
    {
        cout << -1;
        return 0;
    }
    
    binary_research();
    cout << ans;
    
    return 0;
}
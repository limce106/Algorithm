#include <iostream>
using namespace std;

int main()
{
    int n;
    int ans = -1;
    cin >> n;
    
    if(n % 5 == 0)    // O(1)
        ans = n / 5;
    else
    {
        for(int i = n / 5; i >= 0; i--)    // O(n/5) = O(n)
        {
            if((n - 5 * i) % 3 == 0)    // O(1)
            {
                ans = i  + (n - 5 * i) / 3;
                break;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}

// 시간복잡도: O(n)

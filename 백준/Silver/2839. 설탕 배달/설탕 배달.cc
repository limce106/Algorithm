#include <iostream>
using namespace std;

int main()
{
    int n;
    int ans = -1;
    cin >> n;
    
    if(n % 5 == 0)
        ans = n / 5;
    else
    {
        for(int i = n / 5; i >= 0; i--)
        {
            if((n - 5 * i) % 3 == 0)
            {
                ans = i  + (n - 5 * i) / 3;
                break;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    
    int sushi[30001];
    bool eat[30001] = {false};
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        cin >> sushi[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        int coupon = 1;
        int flag = 0;
        
        for(int j = i; j < i + k; j++)
        {
            if(!eat[sushi[j % n]])
            {
                eat[sushi[j % n]] = true;
            }
            else
            {
                flag++;
            }
        }
        
        if(eat[c])
            coupon = 0;
        
        ans = max(ans, k - flag + coupon);
        memset(eat, false, sizeof(eat));
    }
    
    cout << ans;
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> cityLen(n-1);
    vector<int> price(n-1);
    int ans = 0;
    
    for(int i = 0; i < n - 1; i++)
    {
        cin >> cityLen[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        cin >> price[i];
    }
    
    int minPrice = 1000000000;
    for(int i = 0; i < n - 1; i++)
    {
        minPrice = min(minPrice, price[i]);
        ans += min(price[i] * cityLen[i], minPrice * cityLen[i]);
    }
    
    cout << ans;
    
    return 0;
}
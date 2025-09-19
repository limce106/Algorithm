#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    int left = 1;
    int right = v.back() - v.front();
    int ans = 0;
    
    while(left <= right)
    {
        int mid = (left + right) / 2;
        int last = v[0];
        int installed = 1;
        
        for(int i = 1; i < n; i++)
        {
            if(v[i] - last >= mid)
            {
                installed++;
                last = v[i];
            }
        }
        
        if(installed >= c)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    cout << ans;
    
    return 0;
}
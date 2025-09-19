#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        
        if(input == 1)
            v.push_back(i);
    }
    
    if(v.size() < k)
    {
        cout << -1;
        return 0;
    }
    
    int ans = 1000001;
    for(int i = 0; i <= v.size() - k; i++)
    {
        ans = min(ans, v[i+k-1] - v[i]+1);
    }
    
    cout << ans;
    
    return 0;
}
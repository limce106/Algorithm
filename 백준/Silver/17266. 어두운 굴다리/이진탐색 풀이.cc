#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

bool isPossible(int h)
{
    if(v[0] - h > 0)
        return false;
    
    if(v[m - 1] + h < n)
        return false;
    
    for(int i = 1; i < m; i++)
    {
        if(v[i] - v[i - 1] > 2 * h)
            return false;
    }
    
    return true;
}

int main()
{
    cin >> n >> m;
    
    v.resize(m);
    for(int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    
    int start = 0;
    int end = n;
    int ans = n;
    
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if(isPossible(mid))
        {
            end = mid - 1;
            ans = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    
    cout << ans;
    
    return 0;
}

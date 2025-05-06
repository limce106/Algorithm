#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m;
vector<int> vn;
vector<int> vm;

int binary_research(int a)
{
    int start = 0;
    int end = vm.size() - 1;
    int mid = 0;
    int index = -1;
    
    while(start <= end)
    {
        mid = (start + end) / 2;
        
        if(vm[mid] > a)
        {
            index = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    
    return (vm.size() - index) + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    
    while(t--)
    {
        cin >> n >> m;
        
        vector<int> a(n);
        vector<int> b(m);
        
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int j = 0; j < m; j++)
        {
            cin >> b[j];
        }
        sort(b.begin(), b.end());
        
        int ans = 0;
        for(int k = 0; k < n; k++)
        {
            ans += lower_bound(b.begin(), b.end(), a[k]) - b.begin();
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}

// lower_bound: 주어진 값 이상이 처음 등장하는 위치
// upper_bound: 주어진 값 초과가 처음 등장하는 위치

// 시간 복잡도: 각 a[i]마다 lower_bound(b.begin(), b.end(), a[i]) → O(log M)씩, 총 O(N log M)
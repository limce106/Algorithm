#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> vn, vm;

void binary_research(int target)
{
    int start = 0;
    int end = n - 1;
    int mid = 0;
    
    while(start <= end)
    {
        mid = (start + end) / 2;
        if(target == vn[mid])
        {
            cout << 1 << "\n";
            return;
        }
        else if(target < vn[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    
    cout << 0 << "\n";
}

int main()
{  
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        vn.push_back(input);
    }
    
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int input;
        cin >> input;
        vm.push_back(input);
    }
    
    sort(vn.begin(), vn. end());
    
    for(int i = 0; i < m; i++)
    {
        binary_research(vm[i]);
    }
    
    return 0;
}
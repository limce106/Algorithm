#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> vn;
vector<int> vm;

int countByRange(vector<int>& v, int leftValue, int rightValue)
{
    vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
    return rightIndex - leftIndex;
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
    sort(vn.begin(), vn.end());
    
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int input;
        cin >> input;
        vm.push_back(input);
    }
    
    for(int i = 0; i < m; i++)
    {
        cout << countByRange(vn, vm[i], vm[i]) << ' ';
    }
    
    return 0;
}

// 시간 복잡도: O(N log N + M log N)
// sort: O(N log N)
// lower_bound / upper_bound → 각각 O(log N), M번 호출되므로 O(M log N)

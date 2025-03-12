#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> v;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        v.push_back(t + 1);
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    int ans = -1;
    for(int i = 0; i < n; i++){
        ans = max(ans, v[i] + i);
    }
    cout << ans  + 1;
    
    return 0;
}
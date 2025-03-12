#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> v;
    for(int i = 0; i < n; i++){
        int c; 
        cin>> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end(), greater<int>());
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i % 3 != 2){
            ans += v[i];
        }
    }
    cout << ans;
    
    return 0;
}
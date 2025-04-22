#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> v;
int main(){
    cin >> n;
    while(n > 0){
        v.push_back(n % 10);
        n = n / 10;
    }
    
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
    }
    
    return 0;
}
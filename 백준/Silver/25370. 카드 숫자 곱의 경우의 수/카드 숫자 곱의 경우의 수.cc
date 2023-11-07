#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>arr;
int n;

void recursion(int count, int multiple){
    if(count == n){
        arr.push_back(multiple);
        return;
    }
    
    for(int i = 1; i <= 9; i++){
        recursion(count + 1, multiple * i);
    }
}

int main(){
    cin >> n;

    recursion(0, 1);
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    cout << arr.size();
    
    return 0;
}
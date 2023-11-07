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

    // 카드 개수만큼 for문 실행
    for(int i = 1; i <= 9; i++){
        recursion(count + 1, multiple * i);
    }
}

int main(){
    cin >> n;

    recursion(0, 1);

    // 오름차순으로 정렬 후 중복을 제거해야 제거된다. 정렬하지 않고 중복을 제거하려고 하면 제거되지 않는다.
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    cout << arr.size();
    
    return 0;
}

#include <iostream>
#include <set>
using namespace std;

int n;
int number[4] = {1, 5, 10, 50};
set<int> s;

void solve(int idx, int count, int sum){
    if(count == n){
        s.insert(sum);
        return;
    }
    for(int i = idx; i < 4; i++){
        solve(i, count + 1, sum + number[i]);
    }
}

int main(){
    cin >> n;
    
    solve(0, 0, 0);
    cout << s.size() << "\n";
    
    return 0;
}

// 최악의 경우 재귀 호출 횟수: O((n + 3)^3)
// 시간 복잡도: O((n + 3)³ * log K)

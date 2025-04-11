#include<iostream>
#include<vector>
using namespace std;

int n, k;
vector<int> weight;
vector<bool> visit;
int ans = 0;

void solve(int curWeight, int kitCnt){
    if(kitCnt == n){
        ans++;
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(visit[i] == false){
            int todayWeight = curWeight - k + weight[i];
            if(todayWeight < 500){
                continue;
            }
                        
            visit[i] = true;
            solve(todayWeight, kitCnt + 1);
            visit[i] = false;
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        weight.push_back(input);
        visit.push_back(false);
    }
    
    solve(500, 0);
    cout << ans << "\n";
    
    return 0;
}

// 시간 복잡도: O(n!)
// 가능한 모든 순열 탐색

// todayWeight < 500 조건을 for문 밖으로 빼고 return; 하면 효율적

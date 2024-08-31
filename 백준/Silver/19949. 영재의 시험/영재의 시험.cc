#include <iostream>
using namespace std;

int answers[10];
int result = 0;

void dfs(int idx, int score, int choice, int cnt){
    if(idx == 10){
        if(score >= 5){
            result++;
        }
        return;
    }
    
    for(int i = 1; i  <= 5; i++){ // 5지선다
        int nextCnt = choice == i ? cnt + 1 : 1;
        if(nextCnt == 3){ // 3번 연속 같은 번호가 나오면 무시
            continue;
        }
        
        int nextScore = score + (answers[idx] == i);
        dfs(idx + 1, nextScore, i, nextCnt);
    }
}

int main(){
    for(int i = 0; i < 10; i++)
        cin >> answers[i];
    
    dfs(0, 0, -1, 0);
    cout << result;
    
    return 0;
}
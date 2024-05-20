#include <iostream>
using namespace std;

int dp[501][501];

int Max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> dp[i][j];
        }
    }
    
    int maxValue = dp[0][0];
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){ // i줄의 가장 왼쪽 노드, i-1줄의 가장 왼쪽 노드를 더해준다.
                dp[i][j] += dp[i - 1][j];
            }
            else if(i == j){ // i줄의 가장 오른쪽 노드, i-1줄의 가장 오른쪽 노드를 더해준다.
                dp[i][j] += dp[i - 1][j - 1];
            }
            else{
                dp[i][j] += Max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
            
            if(i == n - 1){ // 마지막 줄일 때
                maxValue = Max(maxValue, dp[i][j]); // 마지막 줄 노드들 중 가장 큰 값을 출력하기 위함.
            }
        }
    }
    // 노드 합이 누적되어 dp 값은 최종적으로 아래와 같다.
    // 7
    // 10 15
    // 18 16 15
    // 20 25 20 19
    // 24 30 27 26 24
    
    cout << maxValue;
    
    return 0;
}
#include <iostream>
using namespace std;

int dp[1001][1001];

int max(int a, int b, int c){
    int temp = a > b ? a : b;
    return temp > c ? temp : c;
}

int main(){
    int N, M;
    cin >> N >> M;
    
    // 꼭 (0, 0)이 아닌 (1, 1)부터 채워주어야 i - 1, j - 1을 계산할 때 문제가 생기지 않는다.
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> dp[i][j];
        }
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    cout << dp[N][M];
    
    return 0;
}
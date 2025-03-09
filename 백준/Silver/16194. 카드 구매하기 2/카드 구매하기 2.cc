#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    int dp[1001]; 
    for(int i = 1; i <= N; i++){
        cin >> dp[i];
    }
    
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= i/2; j++){
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
    }
    
    cout << dp[N] << endl;
    
    return 0;
}

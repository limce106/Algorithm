#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    int n[70] = {-1};
    for(int i = 0; i < t; i++){
        cin >> n[i];
    }
    
    long long dp[68];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 3; i < 68; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
    }
    
    for(int i = 0; i < t; i++){
        if(n[i] == -1)
            break;
        
        cout << dp[n[i]] << endl;
    }
    
    return 0;
}
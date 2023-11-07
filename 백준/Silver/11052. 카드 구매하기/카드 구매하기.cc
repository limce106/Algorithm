#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int price[10000];
    int dp[10000];
    
    dp[0] = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i], dp[i-j]+price[j]);
        }
    }
    
    cout << dp[n];

    return 0;
}
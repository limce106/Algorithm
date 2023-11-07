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
            // i개수 카드팩 하나를 사는 것과 i이하 개수 카드팩들을 조합해서 사는 것 중 어느 것이 더  비싼지 비교해서
            // 더 비싼 것은 dp[i]에 넣음
            // 즉, dp[i]는 i개수 카드팩을 살 때 가장 비싸게 사는 가격값을 가지고 있음
            // 예를 들어, 3개를 살 때 3개 한 팩 가격과 (1개 + 2개 팩)가격을 비교
            dp[i] = max(dp[i], dp[i-j]+price[j]);
        }
    }
    
    cout << dp[n];

    return 0;
}

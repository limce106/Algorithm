#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // int가 아닌 long long으로 선언해야 오버플로우가 발생하지 않음!!
    // int는 32비트의 범위를 가짐(-2^31 ~ 2^31 -1 == -2,147,483,647 ~ 2,147,483,647)
    // 예제의 t(25)가 int의 범위를 넘어서는 것을 볼 수 있음.
    long long dp[36] = { 0 };
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i - 1; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    cout << dp[n];
    return 0;
}
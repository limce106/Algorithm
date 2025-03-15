#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> price(N);

    for (int i = 0; i < N; i++) {
        cin >> price[i];
    }

    long long maxProfit = 0;
    int maxPrice = 0;

    // 뒤에서부터 탐색
    for (int i = N - 1; i >= 0; i--) {
        if (price[i] > maxPrice) {
            maxPrice = price[i];  // 최고가 갱신
        } else {
            maxProfit += maxPrice - price[i];  // 차익 계산
        }
    }

    cout << maxProfit << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
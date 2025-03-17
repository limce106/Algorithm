#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // true로 초기화 하려고 하면 첫 번째 원소만 true가 된다. for문 등으로 초기화 해주어야 한다.
    bool mix[201][201] = { false };
    for (int i = 0; i < m; i++) {
        int p, q;
        cin >> p >> q;
        mix[p][q] = mix[q][p] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (mix[i][j] == true)
                continue;

            for (int k = j + 1; k <= n; k++) {
                if (mix[i][k] == true || mix[j][k] == true)
                    continue;
                else
                    ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
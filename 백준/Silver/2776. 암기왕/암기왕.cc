#include <iostream>
#include <unordered_map>
using namespace std;

void solve() {
    int n, m;
    cin >> n;

    unordered_map<int, int> um;
    // O(n)
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        um.insert({ p, 1 });
    }

    cin >> m;
    // O(m)
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        
        if (um[q] == 1) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }

    // 한 번의 테스트 케이스(solve 함수)의 시간 복잡도: O(n + m)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    // O(T×(n + m))
    for (int i = 0; i < T; i++) {
        solve();
    }

    return 0;
}

// 전체 시간 복잡도는 O(T×(n + m))

// 공간 복잡도
// unordered_map의 공간 사용량 → O(N)
// 기타 변수(n, m, T, p, q 등)와 입출력 버퍼 공간 → O(1)
// 총 공간 복잡도 O(n)
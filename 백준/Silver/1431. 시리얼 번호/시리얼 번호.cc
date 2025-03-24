#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// O(L)
int sum(string s) {
    int total = 0;

    for(int i = 0; i < s.size(); i++){
        if (s[i] >= '0' && s[i] <= '9') {
            // '0'의 ASCII 값은 48. 이 방식은 문자열 내에 있는 숫자 문자를 정수로 변환할 때 자주 사용
            total += s[i] - '0';
        }
    }

    return total;
}

bool cmp(string a, string b) {
    int asize = a.size();
    int bsize = b.size();

    if (asize != bsize)
        return asize < bsize;
    
    if (sum(a) != sum(b))
        return sum(a) < sum(b);

    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // O(N * L)
    vector<string> v(n);  

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // O(N log N) -> 시리얼 번호의 최대 길이가 50이므로 O(50 log 50 * 50)
    sort(v.begin(), v.end(), cmp);

    // O(N)
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }

    return 0;
}

// N: 기타의 개수 (최대 50)
// L: 시리얼 번호의 길이 (최대 50)
// 총 시간 복잡도: O(N log N * L)

// 공간 복잡도
// sum()이나 cmp()에서 사용하는 임시 변수들은 상수 공간 → O(1)
// 총 공간 복잡도: O(N * L)

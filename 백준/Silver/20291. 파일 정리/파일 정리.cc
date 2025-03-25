#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// 문자열 개수: n
// 파일 이름의 길이: L

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // O(n * L)
    vector<string> fileNames;

    // map은 key을 자동으로 사전순으로 정렬
    // 거꾸로 정렬하고 싶다면 map<string, int, greater<string>>
    // O(n * L)
    map<string, int> namecountmap;

    for (int i = 0; i < n; i++) {
        // O(L)
        string file;
        cin >> file;

        // O(L)
        int dot = file.find('.');

        // operator[]를 사용하면 키가 없을 경우 자동으로 0을 기본값으로 추가
        // ++ 연산으로 1 증가 (즉, 1이 됨)
        // map의 삽입 및 검색은 O(log m), 전체 시간 복잡도는 O(n * log n)
        namecountmap[file.substr(dot + 1)]++;
    }

    for (auto iter : namecountmap) {
        // O(n)
        cout << iter.first << ' ' << iter.second << endl;
    }

    return 0;
}

// 총 시간 복잡도: O(n * log n)
// 총 공간 복잡도: O(n * L)

#include <iostream>
#include <set>
#include <string>
using namespace std;

struct compare {
    bool operator()(const string& a, const string& b) const {
        if (a.length() != b.length())
            return a.length() < b.length();
        else
            return a < b;
    }
};

int main() {
    int n;
    cin >> n;

    set<string, compare> s;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        s.insert(input);
    }

    for (const auto& str : s) {
        cout << str << "\n";
    }

    return 0;
}

// std::set은 균형 이진 탐색 트리로 구현되어 있음
// 따라서 insert, find, erase 등의 연산은 모두 O(log N) 시간 복잡도
// 최종 시간 복잡도: O(N log N)

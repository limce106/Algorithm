#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        reverse(input.begin(), input.end());
        s[i] = input;
    }

    int length = 1;

    while (true) {
        // 중복을 허용하지 않는 set의 특성 이용
        set<string> setS;

        for (int i = 0; i < n; i++) {
            string temp = s[i].substr(0, length);
            setS.insert(temp);
        }

        // 'setS의 개수 == 학생 수'라면 중복이 없었다는 것
        if (setS.size() == n) {
            break;
        }
        else {
            length++;
        }
    }

    cout << length;

    return 0;
}
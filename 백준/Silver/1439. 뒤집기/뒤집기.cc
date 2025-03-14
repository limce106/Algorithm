#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int zero = 0;
    int one = 0;

    for (int i = 0; i < s.length(); i++) {
        if (i == 0 || (i > 0 && s[i] != s[i-1])) {
            if (s[i] == '0') {
                zero++;
            }
            else {
                one++;
            }
        }
    }

    if (zero == 0 || one == 0) {
        cout << 0;
    }
    else if (zero <= one) {
        cout << zero;
    }
    else {
        cout << one;
    }
}
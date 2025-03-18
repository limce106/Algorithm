#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    int ans = a.length();
    for (int i = 0; i < b.length() - a.length() + 1; i++) {
        int temp = 0;
        for (int j = 0; j < a.length(); j++) {
            if (a[j] != b[i + j]) {
                temp++;
            }
        }
        ans = min(ans, temp);
    }

    cout << ans << endl;

    return 0;
}
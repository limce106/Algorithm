#include <iostream>
using namespace std;

int main() {
    int line;
    int m = 1;
    cin >> line >> m;
    int min_one = 1000;
    int min_six = 1000;
    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (min_six > a) {
            min_six = a;
        }
        if (min_one > b) {
            min_one = b;
        }

        // min_six = min(min_six, x);
        // min_one = min(min_one, y);
    }

    int price1 = (line / 6 + 1) * min_six;    // 패키지로만 살 때
    int price2 = line / 6 * min_six + line % 6 * min_one;    // 패키지, 낱개로 살 때
    int price3 = line * min_one;    // 낱개로만 살 때

    cout << min(price1, min(price2, price3));

    return 0;
}

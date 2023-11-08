#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n = 0;
int cnt = 0;

void recursion(float j, float h) {
    int large = max(j, h);
    int small = min(j, h);

    if (j == h) {
        cout << cnt;
    }
    else{
        cnt++;
        recursion(round(j / 2), round(h / 2));
    }
}

int main() {
    float jimin, hansu;
    cin >> n >> jimin >> hansu;

    recursion(jimin, hansu);
    return 0;
}
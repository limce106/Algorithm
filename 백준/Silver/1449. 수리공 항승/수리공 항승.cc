#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), less<int>());

    int ans = 0;
    float tapeEndPoint = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > tapeEndPoint) {
            tapeEndPoint = v[i] - 0.5 + l;
            ans++;
        }
    }

    cout << ans;

    return 0;
}
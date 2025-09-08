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
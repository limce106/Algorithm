#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<string, int> namecountmap;

    for (int i = 0; i < n; i++) {
        string file;
        cin >> file;
        int dot = file.find('.');
        namecountmap[file.substr(dot + 1)]++;
    }

    for (auto iter : namecountmap) {
        cout << iter.first << ' ' << iter.second << endl;
    }
}
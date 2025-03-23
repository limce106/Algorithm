#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int n, c;
unordered_map<int, int> mp, mp_first;    // O(n)
vector<pair<int, int>> v;    // O(n)
 
bool cmp(pair<int, int> a, pair<int, int> b) {    // O(n)
	if (a.first == b.first) {
		return mp_first[a.second] < mp_first[b.second];
	}
	return a.first > b.first;
}

int main() {
	cin >> n >> c;
    
    // O(n)
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		mp[tmp]++;
		if (mp_first.find(tmp) == mp_first.end()) mp_first[tmp] = i;
	}
    
    // O(n)
	for (auto i : mp)
        v.push_back({i.second, i.first});
    
    // O(n log n)
	sort(v.begin(), v.end(), cmp);

    // O(n)
	for (auto i : v) {
		for (int j = 0; j < i.first; j++) {
			cout << i.second << ' ';
		}
	}
	cout << '\n';
	
	return 0;
}

// 총 시간 복잡도: O(n log n)
// 총 공간 복잡도: O(n)

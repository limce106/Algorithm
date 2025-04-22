#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, m;
map<string, bool> name;
vector<string> ans;

int main()
{
    int count = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        name.insert({input, true});
    }
    for(int i = 0; i < m; i++){
        string input;
        cin >> input;
        
        if(name[input]){
            ans.push_back(input);
            count++;
        }
    }
    
    cout << count << "\n";
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    
    return 0;
}

// C++ STL의 map은 Red-Black Tree
// name.insert({input, true}); -> O(N log N)
// if(name[input]) -> O(M log N)
// 정렬 -> 듣보잡의 수를 D라고 하면 O(D log D)
// 시간 복잡도: O(N log N + M log N + D log D)

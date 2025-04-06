#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int n, k;
vector<string> v;
vector<bool> visit;
set<string> setS;

void solve(string s, int count){    
    if(count == k){
        setS.insert(s);
        return;
    }
    else{
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                visit[i] = true;
                solve(s + v[i], count + 1);
                visit[i] = false;
            }
        }
    }
}

int main(){
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        v.push_back(input);
        visit.push_back(false);
    }
    
    solve("", 0);
    cout << setS.size() << "\n";
    
    return 0;
}

// 중복 없이 n개 중 k개를 고르는 순열이므로 P(n,k)
// set<string>::insert()는 O(log M), M은 조합 개수
// 시간복잡도: O(P(n,k)⋅logP(n,k))

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
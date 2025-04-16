#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string num;
string ans;
vector<char> v;
vector<bool> visit;
bool findAns = false;

void solve(int count){
    if(findAns)
            return;
    
    if(count == num.length()){
        if(stoi(ans) > stoi(num)){
            cout << ans << "\n";
            findAns = true;
        }
        return;
    }
    
    for(int i = 0; i < v.size(); i++)
    {
        if(!visit[i]){
            ans += v[i];
            visit[i] = true;
            solve(count + 1);
            ans.pop_back();    // 문자 하나 제거
            visit[i] = false;
        }
    }
}

int main(){
    cin >> num;
    
    for(int i = 0; i < num.length(); i++){
        v.push_back(num[i]);
        visit.push_back(false);
    }
    
    sort(v.begin(), v.end());    // 순열을 오름차순으로
    solve(0);
    
    if(!findAns)
        cout << 0 << "\n";
    
    return 0;
}
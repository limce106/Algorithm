#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int levelN[5];
    int level, time;
    vector<int> solveN[5];
    
    cin >> n;
    for(int i = 0; i < 5; i++){
        cin >> levelN[i];
    }
    
    for(int i = 0; i < n; i++){
        cin >> level >> time;
        solveN[level-1].push_back(time);
    }
    
    int ans = 0;
    for(int i = 0; i < 5; i++){
        sort(solveN[i].begin(), solveN[i].end());
        
        for(int j = 0; j < levelN[i]; j++){
            ans += solveN[i][j];
            if (j > 0){
                ans += abs(solveN[i][j] - solveN[i][j-1]);
            }
        }
        ans += 60;
    }
    
    ans -= 60;
    cout << ans;
}
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
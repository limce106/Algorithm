#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> rion_position;
    
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        
        if(input == 1)
            rion_position.push_back(i);
    }
    
    int ans = 1000001;
    
    if(rion_position.size() < k)
    {
        cout << -1;
        return 0;
    }
    
    for(int i = 0; i <= rion_position.size() - k; i++)
    {
        ans = min(ans, rion_position[i + k - 1] - rion_position[i] + 1);
    }
    
    cout << ans;
    
    return 0;
}
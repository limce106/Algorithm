#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    
    vector<int> sushi(n);
    for(int i = 0; i < n; i++)
    {
        cin >> sushi[i];
    }
    
    int uniqueCnt = 0;
    int eat[3001] = {0,};
    int ans = 0;
    
    for(int i = 0; i < k; i++)
    {
        if(eat[sushi[i]] == 0)
        {
            uniqueCnt++;
        }
        eat[sushi[i]]++;
    }
    
    ans = uniqueCnt + (eat[c] == 0 ? 1 : 0);
    
    for(int i = 1; i < n; i++)
    {
        int next = sushi[(i + k - 1) % n];
        int before = sushi[i - 1];
        
        if(eat[next] == 0)
            uniqueCnt++;
        
        eat[next]++;
        eat[before]--;
        
        if(eat[before] == 0)
            uniqueCnt--;
        
        ans = max(ans, uniqueCnt + (eat[c] == 0 ? 1 : 0));
    }
    
    cout << ans;
    
    return 0;
}
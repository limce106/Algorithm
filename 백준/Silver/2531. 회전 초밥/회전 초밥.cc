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
    
    vector<int> cnt(d + 1, 0); // 각 종류별 개수
    int uniqueCnt = 0;    // 중복되지 않는 초밥 종류 개수
    
    // 초기 윈도우 [0, k-1]
    for (int i = 0; i < k; i++) {
        if (cnt[sushi[i]] == 0) 
            uniqueCnt++;
        
        cnt[sushi[i]]++;
    }
    
    int ans = uniqueCnt + (cnt[c] == 0 ? 1 : 0);
    
    for (int i = 1; i < n; i++) 
    {
        int left = sushi[i - 1];
        cnt[left]--;
        
        if (cnt[left] == 0) 
            uniqueCnt--;
        
        int right = sushi[(i + k - 1) % n];
        if (cnt[right] == 0)
            uniqueCnt++;
        
        cnt[right]++;
        
        ans = max(ans, uniqueCnt + (cnt[c] == 0 ? 1 : 0));
    }
    
    cout << ans;
    
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int  n = s.size();
    int cntA = count(s.begin(), s.end(), 'a');
    if(cntA == 0 || cntA == n)
    {
        cout << 0;
        return 0;
    }
    
    // 문자열을 2배로 이어붙이기. 원형 구간을 표현하기 위함
    s += s;
    
    int curB = 0;
    for(int i = 0; i < cntA; i++)
    {
        if(s[i] == 'b')
            curB++;
    }
    
    int ans = curB;
    for(int i = cntA; i < s.size(); i++)
    {
        if(s[i-cntA] == 'b')
            curB--; // 윈도우에서 "빠져나가는 문자"가 b라면 b 개수 감소
        if(s[i] == 'b')
            curB++;  // 윈도우에 "새로 들어오는 문자"가 b라면 b 개수 증가
        
        ans = min(ans, curB);
    }
    
    cout << ans;
    
    return 0;
}
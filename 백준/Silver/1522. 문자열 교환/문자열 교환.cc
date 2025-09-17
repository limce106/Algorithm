#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int cntA = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'a')
            cntA++;
    }
    
    if(cntA == 0 || cntA == s.size())
    {
        cout << "0";
        return 0;
    }
    
    s += s;
    
    int minCnt = 0;
    int cntB = 0;
    
    for(int i = 0; i < cntA; i++)
    {
        if(s[i] == 'b')
            cntB++;
    }
    
    minCnt = cntB;
    
    for(int i = cntA; i < s.size(); i++)
    {        
        if(s[i] == 'b')
            cntB++;
        if(s[i-cntA] == 'b')
            cntB--;
        
        minCnt = min(minCnt, cntB);
    }
    
    cout << minCnt;
    
    return 0;
}
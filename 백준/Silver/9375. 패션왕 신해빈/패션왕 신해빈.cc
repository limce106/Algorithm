#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    while(n-- > 0)
    {
        int m;
        cin >> m;
        
        unordered_map<string, int> um;
        for(int i = 0; i < m; i++)
        {
            string name, type;
            cin >> name >> type;
            
            um[type]++;
        }
        
        int answer = 1;
        for(auto& it : um)
        {
            answer *= (it.second+1);
        }
        
        cout << answer-1 << endl;
    }
    
    return 0;
}
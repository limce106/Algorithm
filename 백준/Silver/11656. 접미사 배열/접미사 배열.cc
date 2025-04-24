#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<string> v;

int main()
{
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        string subStr = s.substr(i);
        v.push_back(subStr);
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
    
    return 0;
}
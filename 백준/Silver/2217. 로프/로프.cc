#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    int maxWeight = v[0];
    for(int i = 0; i < v.size();i++)
    {
        int curWeight = v[i] * (i + 1);
        if(curWeight > maxWeight)
            maxWeight = curWeight;
    }
    cout << maxWeight;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> v(m);
    for(int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    
    int maxDistance = 0;
    for(int i = 0; i < m; i++)
    {
        if(i == 0)
        {
            maxDistance = max(maxDistance, v[i]);
        }
        else
        {
            int curDistance = ceil((float)(v[i] - v[i - 1]) / 2);
            maxDistance = max(maxDistance, curDistance);
        }
    }
    maxDistance = max(maxDistance, n - v[m - 1]);
    
    cout << maxDistance;
    
    return 0;
}
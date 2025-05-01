#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> HIdx;
vector<int> PIdx;
int ans = 0;

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        char input;
        cin >> input;
        
        if(input == 'H')
            HIdx.push_back(i);
        else
            PIdx.push_back(i);
    }

    for(int i = 0; i < PIdx.size(); i++)
    {
        if(HIdx.size() == 0)
            break;
        
        for(int j = 0; j < HIdx.size(); j++)
        {
            if(abs(PIdx[i] - HIdx[j]) <= k)
            {
                ans++;
                HIdx.erase(HIdx.begin() + j);
                break;
            }
            else if(HIdx[j] > PIdx[i])
            {
                break;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
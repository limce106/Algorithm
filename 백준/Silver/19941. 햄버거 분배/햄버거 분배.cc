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

// 시간 복잡도: 최악의 시간복잡도는 erase로 인해 O(N²)이지만, abs(P - H) <= k만 비교하므로 실제 실행 속도는 거의 O(N)
// 투 포인터로 최적화하면 erase를 사용하지 않아 O(N) 보장 가능

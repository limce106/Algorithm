#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int N;                    // 문제 수
int arr[5];                // 풀 문제 수
vector<int> solNum[5];    // 난이도 별 풀 문제들
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> N;
 
    for (int i = 0; i < 5; ++i)
    {
        cin >> arr[i];
    }
 
    int k, t;
    for (int i = 0; i < N; ++i)
    {
        cin >> k >> t;
        solNum[k-1].push_back(t);
    }
 
 
    int result = 0;
    for (int i = 0; i < 5; ++i)
    {
        sort(solNum[i].begin(), solNum[i].end());
        for (int j = 0; j < arr[i]; ++j)
        {
            result += solNum[i][j];            // 풀이에 걸리는 시간
            if (j > 0)
            {
                result += abs(solNum[i][j] - solNum[i][j - 1]);        // 휴식 시간
            }
        }
        result += 60;
    }
 
    result -= 60;
 
    cout << result;
}
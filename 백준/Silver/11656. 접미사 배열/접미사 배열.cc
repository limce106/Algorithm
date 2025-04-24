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

// 접미사 생성: s.size()개의 접미사를 생성. s.substr(i)는 길이 O(n - i)의 문자열을 생성하므로, 전체 시간 복잡도는 O(n²)
// 정렬: 정렬 O(n log n) * 각 문자열 비교 시간(O(n)) = O(n² log n)
// 출력: O(n²)
// 시간 복잡도: O(n² log n)

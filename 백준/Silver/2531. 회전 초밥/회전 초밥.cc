#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n, d, k, c; // 접시의 수, 초밥의 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호
    cin >> n >> d >> k >> c;
    
    int arr[30001]; // 회전 초밥 테이블
    bool check[30001];
    int maxCnt = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        int flag = 0; // 중복 개수
        int coupon = 1;
        
        // 원형임을 고려
        for(int j = i; j < i + k; j++)
        {
            // j는 접시의 개수를 초과할 수 있으므로 나머지로 먹었는지 확인
            if(!check[arr[j % n]])
                check[arr[j % n]] = true;
            else
                flag++;
        }
        
        if(check[c])
            coupon = 0;
        
        maxCnt = max(maxCnt, k - flag + coupon);
        memset(check, false, sizeof(check));
    }
    
    cout << maxCnt << endl;
    
    return 0;
}
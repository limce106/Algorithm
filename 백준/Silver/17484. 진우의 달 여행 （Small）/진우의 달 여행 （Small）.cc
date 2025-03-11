#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int matrix[10][10];
int dp[10][10][3];

//0:왼 1:dir 2:오
int solve(int y, int x, int prevDir){
    // 달에 도착했다면
    if(y == n)
        return 0;
    
    // 메모이제이션을 활용하여 중복 연산 방지
    // ret을 변경하면 dp[y][x][prevDir]의 값도 바로 변경됨 
    int &ret = dp[y][x][prevDir];
    // 초기값이 1이므로 ret == -1이면 아직 계산된 값이 없다는 뜻
    // 즉 이미 계산되었다면 반환
    if(ret != -1)
        return ret;
    
    // INT_MAX의 절반 이하이므로 오버플로우 위험 없이 안전하게 사용 가능
    ret = 0x3f3f3f3f;
    
    // 왼쪽 아래로 이동
    if(x-1 >= 0 && prevDir != 0){
        // + matrix[y][x]: 현재 연료 소모량을 더한다.
        ret = min(ret, solve(y+1, x-1, 0) + matrix[y][x]);
    }
    
    // 오른쪽 아래로 이동
    if(x+1 < m && prevDir != 2) {
        ret = min(ret, solve(y+1, x+1, 2) + matrix[y][x]);
    }
    
    // 직진 이동
    if(prevDir != 1) {
        ret = min(ret, solve(y+1, x, 1) + matrix[y][x]);
    }
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // dp 배열을 1로 초기화
    // void *memset(void *ptr, int value, size_t num); 메모리의 특정 영역을 지정한 값으로 채우는 함수
    // ptr : 초기화할 메모리 블록의 시작 주소
    // value : 설정할 값 (char 단위로 설정됨)
    // num : 초기화할 바이트 크기
    memset(dp, -1, sizeof(dp));
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    
    int ans = 0x3f3f3f3f;
    
    // 모든 열 검사
    for(int i = 0; i < m; i++) {
        // 3: 어떤 방향도 아님
        ans = min(ans, solve(0, i, 3));
    }
    
    cout << ans;
    
    return 0;
}
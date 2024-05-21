#include <iostream>
#include <queue>
using namespace std;

int N;
const int MAX = 201;
int path[MAX][MAX]; // 그 위치까지 이동하기 위한 이동 횟수 저장
bool visited[MAX][MAX]; // 그 위치 방문 여부
queue<pair<int, int>> q;
int dx[6] = {-2,-2,0,0,2,2};
int dy[6] = {-1,1,-2,2,-1,1};

void BFS(int r1, int c1){
    path[r1][c1] = 0;
    q.push({r1, c1});
    
    while(!q.empty()){
        int x = q.front().first; // pair를 사용한 큐에서 앞쪽 값 호출
        int y = q.front().second; // pair를 사용한 큐에서 뒷쪽 값 호출
        q.pop();
        
        for (int i = 0; i < 6; i++) { // 데스 나이트가 이동 가능한 곳으로 차례로 이동
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx < 0 || ny < 0 || nx > N || ny > N) // 체스판을 벗어났을 경우
                continue;
            if (!visited[nx][ny]) { // 방문하지 않았다면
                visited[nx][ny] = true; // 이동한 노드를 방문 처리
                path[nx][ny] = path[x][y] + 1; // path[nx][ny]에는 그 위치까지 이동하기 위한 이동한 횟수가 값으로 저장됨
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    cin >> N;
    
    int a, b, c, d; //r1 c1 r2 c2
    cin >> a >> b >> c >> d;
    
    BFS(a, b);
    
    if (path[c][d] == 0)
        cout << -1;
    else
        cout << path[c][d];
    
    return 0;
}

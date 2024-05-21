#include <iostream>
#include <queue>
using namespace std;

int N;
const int MAX = 201;
int path[MAX][MAX];
bool visited[MAX][MAX];
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
        
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx < 0 || ny < 0 || nx > N || ny > N) // 체스판을 벗어났을 경우
                continue;
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                path[nx][ny] = path[x][y] + 1;
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
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 601;
int N, M;
char arr[MAX][MAX]; // 캠퍼스
bool visit[MAX][MAX]; // 방문여부
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int count = 0; // 만날 수 있는 사람 수
queue<pair<int, int>> q;

void BFS(){
    // 더 이상 갈 공간이 없을 때까지 반복
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            
            if(visit[nx][ny] == false){
                visit[nx][ny] = true;
                
                if(arr[nx][ny] == 'P'){
                    count++;
                }
                q.push({nx, ny}); // 큐에 삽입하여 재귀
            }       
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
 
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'I') { // 처음 도연이가 시작한 지점
                visit[i][j] = true;
                q.push({ i, j }); // 큐에 삽입
            }
            else if (arr[i][j] == 'X') {
                visit[i][j] = true;  // 벽이라면 방문여부를 true 만들어 지나가지 못하게 만듦
            }
        }
    }
    
    BFS();
    
    if (count != 0) { // 한 명이라도 만났을 경우
        cout << count;
    }
    else // 못 만났을 경우
        cout << "TT";
 
    return 0;
}
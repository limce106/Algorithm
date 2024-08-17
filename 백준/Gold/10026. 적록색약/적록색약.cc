#include <iostream>
using namespace std;

const int MAX = 101;
int N;
char arr[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int RGnotEqual = 0;
int RGEqual = 0;

void DFS(int x, int y){
    visit[x][y] = true;
    
    for(int i = 0; i < 4; i++){
        int px = x + dx[i];
        int py = y + dy[i];
        
        if(px < 0 || px >= N || py < 0 || py >= N)
            continue;
        
        // 다음 탐색하는 좌표가 현재 좌표와 색이 같고 방문하지 않았다면
        if(!visit[px][py] && arr[px][py] == arr[x][y]){
            visit[px][py] = true;
            DFS(px, py);
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    // 적록색약이 아닌 사람이 보았을 때의 구역 수
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visit[i][j]){
                DFS(i, j);
                RGnotEqual++; // DFS가 끝났다면 한 구역을 다 돈 것이 되기에 구역의 수 1 증가
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visit[i][j] = false;
            if(arr[i][j] == 'R')
                arr[i][j] = 'G';
        }
    }
    
    // 적록색약인 사람이 보았을 때의 구역 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visit[i][j]){
                DFS(i, j);
                RGEqual++; // DFS가 끝났다면 한 구역을 다 돈 것이 되기에 구역의 수 1 증가
            }
        }
    }
    
    cout << RGnotEqual << ' ' << RGEqual;
    
    return 0;
}

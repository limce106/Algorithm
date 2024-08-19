// 한 번에 성공

#include <iostream>
using namespace std;

const int MAX = 251;
int M, N;
int arr[MAX][MAX];
bool visit[MAX][MAX];
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8]= {0, 0, -1, 1, -1, 1, -1, 1};
int count = 0;

void DFS(int x, int y){
    visit[x][y] = true;
    
    for(int i = 0; i < 8; i++){
        int px = x + dx[i];
        int py = y + dy[i];
        
        if(px < 0 || px >= M || py < 0 || py >= N)
            continue;
        
        if(arr[px][py] == 0 || visit[px][py] == true)
            continue;
        else
            DFS(px, py);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> M >> N;
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j] == 1 && visit[i][j] == false){
                DFS(i, j);
                count++;
            }
        }
    }
    
    cout << count;
    
    return 0;
}

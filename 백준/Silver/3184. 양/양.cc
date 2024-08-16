#include <iostream>
#include <queue>
using namespace std;

const int MAX = 251;
int R, C;
char arr[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int wolf = 0;
int sheep = 0;

void BFS(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    visit[i][j] = true;
    
    int CurW = 0;
    int CurS = 0;
    // BFS를 호출한 칸이 양이나 늑대인지
    if(arr[i][j] == 'o'){
            CurS++;
        }
        else if(arr[i][j] == 'v'){
            CurW++;
        }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int px = x + dx[i];
            int py = y + dy[i];

            // 마당을 벗어나거나 방문했던 칸이거나 울타리일 때
            if(px < 0 || px >= R || py < 0 || py >= C || visit[px][py] || arr[px][py] == '#')
                continue;

            // BFS를 호출한 칸을 제외하고 그 칸을 기준으로 돌아다닌 칸이 양이나 늑대인지
            if(arr[px][py] == 'o'){
                CurS++;
            }
            else if(arr[px][py] == 'v'){
                CurW++;
            }
            
            visit[px][py] = true;
            q.push({px, py});
        }
    }

    // 양이 더 많으면 늑대가 죽고
    if(CurS > CurW){
        wolf -= CurW;
    }
    // 양이 적거나 같으면 양이 죽는다
    else{
        sheep -= CurS;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    cin >> R >> C;

    // 이렇게 입력받는 것도 가능
    /*for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i];
        }
    }*/
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i][j];

            // 구역 상관없이 마당의 모든 양과 늑대의 수 세기
            if(arr[i][j] == 'o'){
                sheep++;
            }
            else if(arr[i][j] == 'v'){
                wolf++;
            }
        }
    }
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){ 
            // 아직 방문하지 않은 칸이고 양이나 늑대일 때 BFS 호출
            if(arr[i][j] != '#' && !visit[i][j]){
                BFS(i, j);
            }
        }
    }
    
    cout << sheep << ' ' << wolf;
    
    return 0;
}

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
            
            if(px < 0 || px >= R || py < 0 || py >= C || visit[px][py] || arr[px][py] == '#')
                continue;
            
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
    
    if(CurS > CurW){
        wolf -= CurW;
    }
    else{
        sheep -= CurS;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    cin >> R >> C;
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i][j];
            
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
            if(arr[i][j] != '#' && !visit[i][j]){
                BFS(i, j);
            }
        }
    }
    
    cout << sheep << ' ' << wolf;
    
    return 0;
}
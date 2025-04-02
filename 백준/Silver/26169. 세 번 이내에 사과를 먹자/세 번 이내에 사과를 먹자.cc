#include<iostream>
using namespace std;

int r, c;
int graph[5][5];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool DFS(int x, int y, int move, int apple){        
    if(apple >= 2){
       return true;
     }
    if(move == 3){
       return false;
     }
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx > 4 || ny > 4)
            continue;
        
        if(graph[nx][ny] == -1)
            continue;
        
        int value = graph[nx][ny];
        graph[nx][ny] = -1;
        
        if(DFS(nx, ny, move + 1, apple + value)){
            return true;
        }
        else{
             graph[nx][ny] = value;   
        }
    }
    return false;
}

int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> graph[i][j];
        }
    }
    
    cin >> r >> c;
    graph[r][c] = -1;    // 출발 지점을 절대 되돌아올 일이 없으므로
    
    cout << (int)DFS(r, c, 0, 0) << "\n";
    
    return 0;
}
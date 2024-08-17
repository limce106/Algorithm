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
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visit[i][j])
                RGnotEqual++;
                DFS(i, j);
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visit[i][j] = false;
            if(arr[i][j] == 'R')
                arr[i][j] = 'G';
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visit[i][j])
                RGEqual++;
                DFS(i, j);
        }
    }
    
    cout << RGnotEqual << ' ' << RGEqual;
    
    return 0;
}
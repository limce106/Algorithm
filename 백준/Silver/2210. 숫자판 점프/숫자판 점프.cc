#include <iostream>
#include <set>
using namespace std;

int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
int arr[5][5];
set<int>s; // 중복을 제외하기 위함

void DFS(int x, int y, int count, int num){
    if(count == 5){ // 다섯 번 이동해서 여섯 자리 숫자가 만들어졌을 때
        s.insert(num);
        return;
    }
    
    for(int i = 0; i < 5; i++){
        // px, py는 현재 좌표(x, y)에서 이동한 좌표 ([0][0] ~ [4][4])
        int px = x + xx[i];
        int py = y + yy[i];
           
        if(px < 0 || py < 0 || px > 4 || py > 4) // 유효한 좌표가 아닐 때
            continue;
            
        DFS(px, py, count + 1, num * 10 + arr[px][py]);
    }
}

int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            DFS(i, j, 0, arr[i][j]);
        }
    }
    
    cout << s.size() << '\n';
    
    return 0;
}
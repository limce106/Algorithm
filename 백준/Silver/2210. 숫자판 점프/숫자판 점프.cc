#include <iostream>
#include <set>
using namespace std;

int arr[5][5];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
set<int>s;

void DFS(int x, int y, int count, int num){
    if(count == 5){
        s.insert(num);
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int px = x + xx[i];
        int py = y + yy[i];
        
        if(px < 0 || py < 0 || px > 4 || py > 4)
            continue;
        
        DFS(px, py, count + 1, num*10 + arr[px][py]);
    }
}

int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            DFS(i, j, 0, arr[i][j]);
        }
    }
    
    cout << s.size() << '\n';
    
    return 0;
}
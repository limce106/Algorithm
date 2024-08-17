// https://everenew.tistory.com/167
// https://cocoon1787.tistory.com/430
// 플로이드-와샬 이용

#include <iostream>
using namespace std;

int N, M;
bool arr[101][101];
// arr[i][j]는 i->j로의 연결이 있는지 여부

void Floyd(){
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                arr[i][j] = arr[i][j] || (arr[i][k] && arr[k][j]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    cin >> M;
    
    for(int i = 1; i <= N; i++){
        arr[i][i] = true;
    }
    
    int u, v;
    for(int i = 1; i <= M; i++){
        cin >> u >>v;
        arr[u][v] = true;
    }
    
    Floyd();
    
    for(int i = 1; i <= N; i++){
        int count = 0;
        for(int j = 1; j <= N; j++){
            // arr[i][j] 와 arr[j][i] 둘다 false라면 연결관계가 아예 없는 것이므로 카운트
            if(arr[i][j] == false && arr[j][i] == false)
                count++;
        }
        cout << count << '\n';
    }
    
    return 0;
}
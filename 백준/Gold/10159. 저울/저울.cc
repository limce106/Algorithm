// https://tooo1.tistory.com/284
// https://everenew.tistory.com/167
// 플로이드-와샬 이용

#include <iostream>
using namespace std;

const int MAX = 101;
int N, M;
bool arr[MAX][MAX];
// arr[i][j]는 i->j로의 연결이 있는지 여부

void Floyd(){
    for(int k = 1; k <= N; k++){ // 거쳐가는 노드
        for(int i = 1; i <= N; i++){ // 출발 노드
            for(int j = 1; j <= N; j++){ // 도착 노드
                if(arr[i][k] && arr[k][j]) // 만약 거쳐갈 수 있다면 (거쳐갈 노드가 존재해야 비교 결과를 알 수 있음)
                    arr[i][j] = true; // 갈 수 있다고 표시
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
    
    int u, v;
    for(int i = 1; i <= M; i++){
        cin >> u >>v;
        arr[u][v] = true; // 갈 수 있다고 표시
    }
    
    Floyd();
    
    for(int i = 1; i <= N; i++){
        int count = 0;
        for(int j = 1; j <= N; j++){
            // 둘다 false라면 연결관계가 아예 없는 것, 갈 수 없는 것이므로 카운트
            if(arr[i][j] == false && arr[j][i] == false)
                count++;
        }
        cout << count - 1 << '\n'; // -1은 자기 자신이 true인 경우
    }
    
    return 0;
}

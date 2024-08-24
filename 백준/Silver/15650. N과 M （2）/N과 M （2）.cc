#include <iostream>
using namespace std;

const int MAX = 9;
int N, M;
int arr[MAX];

void dfs(int num, int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << ' ';
        }
        cout << "\n";
    }
    else{
        for(int i = num; i <= N; i++){
            arr[cnt] = i;
            dfs(i + 1, cnt + 1); // "중복없이" M개이므로 i + 1
        }
    }
}

int main(){
    cin >> N >> M;
    dfs(1, 0);
    
    return 0;
}
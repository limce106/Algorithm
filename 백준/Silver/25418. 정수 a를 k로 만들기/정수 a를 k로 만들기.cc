#include<iostream>
#include<queue>
using namespace std;

int a, k;
int visit[1000001];

void BFS(){
    queue<int> q;
    q.push(a);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(cur == k){
            break;
        }
        if(cur + 1 <= k && !visit[cur + 1]){
            visit[cur + 1] = visit[cur] + 1;
            q.push(cur + 1);
        }
        if(cur * 2 <= k && !visit[cur * 2]){
            visit[cur * 2] = visit[cur] + 1;
            q.push(cur * 2);
        }
    }
}

int main(){
    cin >> a >> k;
    
    BFS();
    cout << visit[k] << "\n";
    
    return 0;
}

// BFS는 O(N) 탐색이므로 최대 O(K)
// 총 시간 복잡도: O(K)

// visit[]: O(K)
// q: BFS에서 최악의 경우 O(K)개의 원소를 저장할 수 있음
// 총 공간 복잡도: O(K)

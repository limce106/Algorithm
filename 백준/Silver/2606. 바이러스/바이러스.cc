#include <iostream>
using namespace std;

int n, m;
bool graph[101][101];
bool visit[101];
int ans = 0;

void DFS(int v){
    visit[v] = true;
    
    for(int i = 1; i <= n; i++){
        if(graph[v][i] == true && !visit[i]){
            ans++;
            DFS(i);
        }
    }
}

int main(){
    cin >> n;
    cin >> m;
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = true;
    }
    
    DFS(1);    
    cout << ans << "\n";
    
    return 0;
}
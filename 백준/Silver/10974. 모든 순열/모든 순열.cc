#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> graph;
vector<bool> visit;

void solve(vector<int> v){
    int size = v.size();
    if(size == n){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << "\n";
        }
        return;
    }
    else{
        for(int i = 1; i < n + 1; i++){
            if(!visit[i]){
                visit[i] = true;
                v.push_back(graph[i]);
                solve(v);
                visit[i] = false;
                v.pop_back();
            }
        }
    }
}

int main(){
    cin >> n;
    graph.resize(n + 1);
    visit.resize(n + 1);
    
    for(int i = 1; i <= n; i++){
        graph[i] = i;
        visit[i] = false;
    }
    
    vector<int> c;
    solve(c);
    
    return 0;
}
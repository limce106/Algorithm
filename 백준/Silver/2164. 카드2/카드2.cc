#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N;
    queue<int> q;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        q.push(i + 1);
    }
    
    int front;
    while(N != 1){
        q.pop();
        front = q.front();
        q.pop();
        q.push(front);
        N--;
    }
    
    cout << q.front();
    
    return 0;
}
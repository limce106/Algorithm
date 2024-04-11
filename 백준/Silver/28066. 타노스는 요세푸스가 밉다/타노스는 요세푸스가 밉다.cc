#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
   
    queue<int> q;
    for(int i = 0; i < N; i++){
        q.push(i + 1);
    }
    
    while(q.size() > 1){
        int first = q.front();
        q.pop();
        q.push(first);
        
        for(int i = 0; i < K - 1; i++){
            if(q.size() == 1){
                break;
            }
            else{
                q.pop();
            }
        }
    }
    
    cout << q.front();
    
    return 0;
}
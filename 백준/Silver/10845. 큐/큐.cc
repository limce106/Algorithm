#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N; // 명령어 수
    queue<int> q;
    string command;
    int pushN;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> command;
        
        if(command == "push"){
            cin >> pushN;
            q.push(pushN);
        }
        else if(command == "pop"){
            if(q.empty()){
                cout << -1 << endl;
            }
            else{
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if(command == "size"){
            cout << q.size() << endl;
        }
        else if(command == "empty"){
            if(q.empty()){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(command == "front"){
            if(q.empty()){
                cout << -1 << endl;
            }
            else{
                cout << q.front() << endl;
            }
        }
        else if(command == "back"){
            if(q.empty()){
                cout << -1 << endl;
            }
            else{
                cout << q.back() << endl;
            }
        }
    }
    
    return 0;
}
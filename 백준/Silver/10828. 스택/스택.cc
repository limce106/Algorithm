#include <iostream>
#include <stack>
using namespace std;

int main(){
    int N; // 명령어 수
    stack<int> s;
    string command; // 명령어
    int pushNum; // push 연산 시 스택에 넣을 정수
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
       cin >> command;
        
        if(command == "push"){
            cin >> pushNum;
            s.push(pushNum);
        }
        else if(command == "pop"){
            if(s.size() == 0){
                cout << -1 << endl;
            }
            else{
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if(command == "size"){
            cout << s.size() << endl;
        }
        else if(command == "empty"){
            if(s.empty()){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(command == "top"){
            if(s.size() == 0){
                cout << -1 << endl;
            }
            else{
                cout << s.top() << endl;
            }
        }
    }
    
    return 0;
}

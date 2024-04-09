#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int N;
    stack<int> s;
    int pushN;
    int command;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> command;
        
        if(command == 1){
            cin >> pushN;
            s.push(pushN);
        }
        else if(command == 2){
            if(s.size() == 0){
                cout << -1 << "\n";
            }
            else{
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if(command == 3){
            cout << s.size() << "\n";
        }
        else if(command == 4){
            if(s.empty()){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(command == 5){
            if(s.size() == 0){
                cout << -1 << "\n";
            }
            else{
                cout << s.top() << "\n";
            }
        }
    }
    
    return 0;
}
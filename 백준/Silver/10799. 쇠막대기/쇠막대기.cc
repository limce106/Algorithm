#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<char> s;
    string str;
    int result = 0;
    
    cin >> str;
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            s.push(str[i]);
            result += 1;
        }
        else{
            // 레이저라면
            if(str[i-1] == '('){
                s.pop();
                result -= 1;
                result += s.size();
            }
            else{
                s.pop();
            }
        }
    }
    
    cout << result;
    
    return 0;
}
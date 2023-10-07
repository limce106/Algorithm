#include <iostream>
using namespace std;

int main(){
    int num, f;
    cin >> num >> f;
    
    num /= 100;
    num *= 100;
    
    while(1){
        if(num % f == 0){
            break;
        }
        else{
            num++;
        }
    }
    
    int answer = num%100;
    
    if(answer < 10){
        cout << "0" << answer;
    }
    else{
        cout << answer;
    }
    
    
    return 0;
}
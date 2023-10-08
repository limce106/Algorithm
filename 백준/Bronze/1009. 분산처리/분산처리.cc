#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    int a, b;
    int c = 1;
    
    for(int i = 0; i < t; i++){
        cin >> a >> b;
        c = 1;
        
        for(int j = 0; j < b; j++){
            c = (c*a)%10;
        }
        
        if(c == 0){
            cout << 10 << endl;
        }
        else{
            cout << c << endl;
        }
    }
    
    return 0;
}
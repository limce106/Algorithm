#include <iostream>
using namespace std;

int main(){
    int cnt;
    cin >> cnt;

    int value[cnt];
    for(int i = 0; i < cnt; i++){
        cin >> value[i];
    }
    
    if(cnt == 1){
        cout << value[0] * value[0];
        return 0;
    }
    
    int max = value[0];
    int min = value[0];
    
    for(int j = 1; j < cnt; j++){
        if(value[j] > max){
            max = value[j];
        }
        if(value[j] < min){
            min = value[j];
        }
    }
    
    cout << max * min;
    
    return 0;
}
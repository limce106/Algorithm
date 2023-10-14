#include <iostream>
using namespace std;

int main(){
    int n, k;
    int arr[11];
    int cnt = 0;
    
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    
    for(int i = n - 1; i >= 0; i--){
        if(k > 0){
            cnt += k/arr[i];
            k = k % arr[i];
        }
        else{
            break;
        }
    }
    
    cout << cnt;
    
    return 0;
}
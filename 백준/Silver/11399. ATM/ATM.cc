#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int arr[10001];
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    int time = 0;
    for(int i = 0; i < n; i++){
        time += arr[i] * (n - i);
    }
    
    cout << time;
    
    return 0;
}
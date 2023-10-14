#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int a[51], b[51];
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    
    sort(a, a + n);
    sort(b, b + n, greater<>());
    
    int answer = 0;
    for(int i = 0; i < n; i++){
        answer += a[i] * b[i];
    }
    
    cout << answer;
    
    return 0;
}
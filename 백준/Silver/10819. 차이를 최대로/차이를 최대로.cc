// 정확히 이해 못 함..

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int arr[9];
bool visited[9];
int Maxi = 0; // 점화식의 최대값

void backtrack(vector<int> v){
    // 순열이 완성되면 점화식 값 계산
    if(v.size() == N){
        int sum = 0;
        
        for(int i = 0; i < N - 1; i++){
            sum += abs(v[i] - v[i+1]);
        }
        Maxi = max(Maxi, sum);
        return;
    }
    
    // 순열 생성
    for(int i = 0; i < N; i++){
        if(!visited[i]){ // 현재 요소가 순열에 포함되지 않았을 때
            visited[i] = true;
            v.push_back(arr[i]); // 해당 요소를 순열에 추가
            backtrack(v); // 재귀 호출을 통해 다음 요소를 결정하고 다음 요소가 계속해서 추가됨
            v.pop_back(); // 순열의 마지막에 추가된 요소를 제거하여 순열의 다른 가능성을 탐색할 수 있게 됨
            visited[i] = false;
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    vector<int> v;
    backtrack(v);
    
    cout << Maxi;
    
    return 0;
}
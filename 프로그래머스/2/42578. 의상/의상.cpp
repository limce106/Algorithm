#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> um;
    
    for(int i = 0; i < clothes.size(); i++)
    {
        um[clothes[i][1]]++;
    }
    
    for(auto& it : um)
    {
        answer *= (it.second+1);
    }
    
    // (개수+1)*(개수+1)*.. -> 전체 경우의 수
    // 모든 의상을 착용하지 않는 경우의 수 제외
    return answer-1;
}
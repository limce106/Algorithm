#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); i++)
    {
        q.push({i, priorities[i]}); // 처음 위치, 우선순위
        pq.push(priorities[i]);     // 우선순위가 높은 순서대로 프로세스 저장
    }
    
    int answer = 0;
    
    while(!q.empty())
    {
        int idx = q.front().first;
        int pri = q.front().second;
        q.pop();
        
        if(pri == pq.top())
        {
            pq.pop();
            answer++;
            if(idx == location)
                return answer;
        }
        else
        {
            q.push({idx, pri});
        }
    }
    
    return -1;
}
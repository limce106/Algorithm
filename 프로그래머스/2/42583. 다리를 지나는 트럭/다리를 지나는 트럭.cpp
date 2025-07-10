#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    queue<pair<int, int>> cur;
    int curWeight = 0;
    
    for(auto w : truck_weights)
    {
        q.push(w);
    }
    
    while(!q.empty())
    {
        answer++;
        
        if(answer - cur.front().second == bridge_length)
        {
            curWeight -= cur.front().first;
            cur.pop();
        }
        
        if(curWeight + q.front() <= weight)
        {
            cur.push({q.front(), answer});
            curWeight += q.front();
            q.pop();
        }
    }
    
    return answer+bridge_length;
}
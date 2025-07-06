#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int curIdx = location;
    
    queue<int> q;
    for(int i = 0; i < priorities.size(); i++)
    {
        q.push(priorities[i]);
    }
    
    sort(priorities.begin(), priorities.end());
    
    while(true)
    {
        if(q.front() == priorities[priorities.size() - 1])
        {
            answer++;
            q.pop();
            priorities.pop_back();
            
            if(curIdx == 0)
                break;
            else
                curIdx--;
        }
        else
        {
            int front = q.front();
            q.pop();
            q.push(front);
            
            if(curIdx == 0)
                curIdx = q.size() - 1;
            else
                curIdx--;
        }
        
    }
    
    return answer;
}
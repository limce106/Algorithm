#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i = 0; i < progresses.size(); i++)
    {
        int remainDay = (100 - progresses[i]) / speeds[i] + ((100 - progresses[i]) % speeds[i] != 0);
        q.push(remainDay);
    }
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        int num = 1;
        
        while(!q.empty() && q.front() <= cur)
        {
            num++;
            q.pop();
        }
        
        answer.push_back(num);
    }
    
    return answer;
}
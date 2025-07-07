#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i = 0; i < progresses.size(); i++)
    {
        int remain = 100-progresses[i];
        
        int day = remain / speeds[i];
        if(remain % speeds[i] != 0)
            day++;
        
        q.push(day);
    }
    
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        int num = 1;
        
        while(!q.empty() && temp >= q.front())
        {
            num++;
            q.pop();
        }
        
        answer.push_back(num);
    }
    
    return answer;
}
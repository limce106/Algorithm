#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int s : scoville)
    {
        pq.push(s);
    }
    
    while(true)
    {        
        if(pq.top() >= K)
            return answer;
        else
        {
            if(pq.size() == 1)
                return -1;
        }
        
        answer++;
        
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        pq.push(a + b*2);
    }
}
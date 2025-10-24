#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int test;
    cin >> test;
    
    while(test--)
    {
        int n, m;
        cin >> n >> m;
        
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            
            q.push({i, input});
            pq.push(input);
        }
        
        while(!q.empty())
        {
            int idx = q.front().first;
            int value = q.front().second;
            q.pop();
            
            if(pq.top() == value)
            {
                pq.pop();
                count++;
                
                if(idx == m)
                {
                    cout << count << endl;
                    break;
                }
            }
            else
            {
                q.push({idx, value});
            }
        }
    }
    
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, input;
    cin >> n;
    
    priority_queue<int> pq;
    
    for(int i = 0; i < n; i++)
    {
        cin >> input;
        
        if(input == 0)
        {
            if(pq.size() == 0)
                cout << -1 << endl;
            else
            {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else
        {
            for(int i = 0; i < input; i++)
            {
                int a;
                cin >> a;
                pq.push(a);
            }
        }
    }
    
    return 0;
}
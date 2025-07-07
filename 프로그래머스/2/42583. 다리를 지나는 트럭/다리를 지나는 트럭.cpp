#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    int time = 0;
    int bridge_weight = 0;
    int index = 0;
    
    while(index < truck_weights.size())
    {
        time++;
        
        if(bridge.size() == bridge_length)
        {
            bridge_weight -= bridge.front();
            bridge.pop();
        }
        
        if(bridge_weight + truck_weights[index] <= weight)
        {
            bridge.push(truck_weights[index]);
            bridge_weight += truck_weights[index];
            index++;
        }
        else
        {
            bridge.push(0);
        }
    }
    
    return time + bridge_length;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int i = 0;
    int j = people.size() - 1;
    
    while(i <= j)
    {
        int weight = people[i] + people[j];
        if(weight <= limit)
        {
            i++;
        }
        j--;
        answer++;
    }
    
    return answer;
}
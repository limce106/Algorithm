#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int answer = 0;
    int i = 0;
    int j = people.size() - 1;
    
    while(i <= j)
    {
        int weight = people[i] + people[j];
        if(weight <= limit)
        {
            i++;
        }
        
        answer++;
        j--;
    }

    return answer;
}
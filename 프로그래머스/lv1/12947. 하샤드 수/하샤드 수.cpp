#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int a = x;
    
    int sum = 0;
    while(x > 0)
    {
        sum += x % 10;
        x /= 10;
    }

    if(a % sum == 0)
    {
        answer = true;
    }
    else
    {
        answer = false;
    }
    return answer;
}
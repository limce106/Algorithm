#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int share = n;

    while(share != 0)
    {
        answer += share % 10;
        share = share / 10;
    }

    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int a = 1;
    vector <int> arr;
    while(n > 0)
    {
        arr.push_back(n%3);
        n /= 3;
    }

    for(int i = arr.size() - 1; i >= 0; i--)
    {
        answer += a*arr[i];
        a*= 3;
    }
    return answer;
}
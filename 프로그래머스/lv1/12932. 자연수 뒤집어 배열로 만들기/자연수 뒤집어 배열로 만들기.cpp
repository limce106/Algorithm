#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    while(n > 0)
    {
        cout << n%10 << endl;
        answer.push_back(n % 10);
        n = n / 10;
    }
    
    return answer;
}
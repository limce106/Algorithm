#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    int numbersSum = 0;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        numbersSum += numbers[i];
    }
    
    answer = (9 * 10 / 2) - numbersSum;
    
    return answer;
}
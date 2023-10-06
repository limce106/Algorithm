#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long n = num;
    int count = 0;
    
    while(true){
        if(n == 1)
            break;
        else if(count == 500)
        {
            count = -1;
            break;
        }
        else
        {
            if(n % 2 == 0)
            {
                n /= 2;
                count++;
            }
            else
            {
                n = n*3 + 1;
                count++;
            }
        }
    }
    
    return count;
}
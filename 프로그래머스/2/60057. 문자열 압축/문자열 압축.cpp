#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for(int i = 1; i <= s.size()/2; i++)
    {
        string compressed = "";
        string prev = s.substr(0, i);
        int count = 1;
        
        for(int j = i; j < s.size(); j += i)
        {
            string next = s.substr(j, i);
            
            if(prev == next)
            {
                count++;
            }
            else
            {
                if(count >= 2)
                    compressed += to_string(count);
                compressed += prev;
                prev = next;
                count = 1;
            }
        }
        
        if(count >= 2)
            compressed += to_string(count);
        compressed += prev;
        
        int compressedLen = compressed.size();
        answer = min(answer, compressedLen);
    }
    
    return answer;
}
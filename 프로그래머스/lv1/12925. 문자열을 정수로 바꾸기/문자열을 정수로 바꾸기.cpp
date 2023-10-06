#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp;

    
    if(s[0] == '+')
    {
        for(int i = 1; i<s.length();i++)
    {
        temp += s[i];
    }
        
        answer = stoi(temp);
    }
    else if(s[0] == '-')
    {
        for(int i = 1; i<s.length();i++)
        {
            temp += s[i];
        }
        answer = stoi(temp) * (-1);
    }
    
    else
    {
        for(int i = 0;i<s.length();i++)
            temp += s[i];
        answer = stoi(temp);
    }
    
    return answer;
}
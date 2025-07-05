#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int num = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            num++;
        }
        else
        {
            if(num > 0)
                num--;
            else
                return false;
        }
    }

    return num == 0;
}
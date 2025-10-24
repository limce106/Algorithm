#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    
    bool isTag = false;
    string temp = "";
    
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '<')
        {
            isTag = true;
            
            for(int i = temp.length()-1; i >= 0; i--)
            {
                cout << temp[i];
            }
            temp = "";
            cout << s[i];
        }
        else if(s[i] == '>')
        {
            isTag = false;
            cout << s[i];
        }
        else if(isTag)
        {
            cout << s[i];
        }
        else
        {
            if(s[i] == ' ')
            {
                for(int j = temp.length()-1; j >= 0; j--)
                {
                    cout << temp[j];
                }
                
                temp = "";
                cout << s[i];
            }
            else
            {
                 temp += s[i];   
            }
        }
    }
    
    for(int j = temp.length()-1; j >= 0; j--)
    {
        cout << temp[j];
    }
    
    return 0;
}
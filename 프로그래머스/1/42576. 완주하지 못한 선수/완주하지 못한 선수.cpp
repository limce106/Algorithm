#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;
    
    for(string p : participant)
    {
        m[p]++;
    }
    
    for(string c : completion)
    {
        m[c]--;
    }
    
    for(auto it : m)
    {
        if(it.second > 0)
            return it.first;
    }
    
    return "";
}
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmpTotal(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

bool cmpPlay(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
        return a.second < b.second;
    
    return a.first > b.first; 
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> total;
    map<string, vector<pair<int, int>>> playindex;
    
    for(int i = 0; i < genres.size(); i++)
    {
        total[genres[i]] += plays[i];
        playindex[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<string, int>> totalVec(total.begin(), total.end());
    sort(totalVec.begin(), totalVec.end(), cmpTotal);
    
    for(auto& it : playindex)
    {
        sort(it.second.begin(), it.second.end(), cmpPlay);
    }
    
    for(auto& it : totalVec)
    {
        string genre = it.first;
        
        auto v = playindex[genre];
        
        for(int i = 0; i < v.size() && i < 2; i++)
        {
            answer.push_back(v[i].second);
        }
    }
    
    return answer;
}
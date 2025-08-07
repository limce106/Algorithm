#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmpTotal(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

bool cmpPlayIdx(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }
    
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> total;
    map<string, vector<pair<int, int>>> playIdx;
    
    for(int i = 0; i < genres.size(); i++)
    {
        total[genres[i]] += plays[i];
        playIdx[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<string, int>> totalV;
    for(auto& it : total)
    {
        totalV.push_back({it.first, it.second});
    }
    
    sort(totalV.begin(), totalV.end(), cmpTotal);
    
    for(auto& it : playIdx)
    {
        sort(it.second.begin(), it.second.end(), cmpPlayIdx);
    }
    
    for(int i = 0; i < totalV.size(); i++)
    {
        string genre = totalV[i].first;
        auto play = playIdx[genre];
        
        for(int j = 0; j < play.size() && j < 2; j++)
        {
            answer.push_back(play[j].second);
        }
    }
    
    return answer;
}
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
    map<string, int> totalPlay;
    map<string, vector<pair<int, int>>> playIdx;
    
    for(int i = 0; i < genres.size(); i++)
    {
        totalPlay[genres[i]] += plays[i];
        playIdx[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<string, int>> v(totalPlay.begin(), totalPlay.end());
    sort(v.begin(), v.end(), cmpTotal);
    
    for(auto& it : playIdx)
    {
        sort(it.second.begin(), it.second.end(), cmpPlay);
    }
    
    for(int i = 0; i < v.size(); i++)
    {
        string genre = v[i].first;
        vector<pair<int, int>> p = playIdx[genre];
        
        for(int j = 0; j < p.size() && j < 2; j++)
        {
            answer.push_back(p[j].second);
        }
    }
    
    return answer;
}
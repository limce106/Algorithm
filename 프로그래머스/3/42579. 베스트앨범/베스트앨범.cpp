#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmpSong(pair<int, int>& a, pair<int, int>& b)
{
    if(a.first == b.first)
        return a.second < b.second;
        
    return a.first > b.first;
}

bool cmpPlaySum(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genrePlaySum; // 장르명, 전체 플레이 횟수
    map<string, vector<pair<int, int>>> genreSongs; // 장르별 (재생횟수, 곡 인덱스)
    
    for(int i = 0; i < genres.size(); i++)
    {
        genrePlaySum[genres[i]] += plays[i];
        genreSongs[genres[i]].push_back({plays[i], i});
    }
    
    for(auto& gs : genreSongs)
    {
        sort(gs.second.begin(), gs.second.end(), cmpSong);
    }
    
    vector<pair<string, int>> genreSort(genrePlaySum.begin(), genrePlaySum.end());
    sort(genreSort.begin(), genreSort.end(), cmpPlaySum);
    
    for(auto& gs : genreSort)
    {
        auto& songs = genreSongs[gs.first];
        for(int i = 0; i < songs.size() && i < 2; i++)
        {
            answer.push_back(songs[i].second);   
        }
    }
    
    return answer;
}
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<pair<int,string>> v;

unordered_map<string,int> m;
unordered_map<string,vector<pair<int,int>>> p;

bool cmp(pair<int,int> &a,pair<int,int> &b) {
    if(a.first==b.first) {
        return a.second<b.second;
    }
    return a.first>b.first;
}

void init_(vector<string> &genres,vector<int> &plays) {
    
    for(int i=0;i<genres.size();i++) {
        m[genres[i]]+=plays[i];
        p[genres[i]].push_back({plays[i],i});
    }
    
    for(pair<string,int> temp:m) {
        v.push_back({temp.second,temp.first});
    }
    sort(v.begin(),v.end(),greater<>());
    
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    vector<int> a;
    
    init_(genres,plays);
    
    for(pair<int,string> temp: v) {

        sort(p[temp.second].begin(),p[temp.second].end(),cmp);     
        // temp.second 는 
        if(p[temp.second].size()<2) {
            for(int i=0;i<1;i++) {
                a.push_back(p[temp.second][i].second);
            }
        } else {
            for(int i=0;i<2;i++) {
                a.push_back(p[temp.second][i].second);
            }
        }
    }
    
    
    return a;
}
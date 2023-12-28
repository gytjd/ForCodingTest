#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;

bool cmpA(pair<int,int> &A,pair<int,int> &B) {
    return A.first<B.first;
}

bool cmpB(pair<int,int> &A,pair<int,int> &B) {
    return A.second<B.second;
}

vector<int> solution(vector<string> wallpaper) {
    vector<pair<int,int>> tempA;
    vector<pair<int,int>> tempB;
    vector<int> answer;
    N=wallpaper.size();
    M=wallpaper[0].size();
    
    int cnt_T=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(wallpaper[i][j]=='#') {
                tempA.push_back({i,j});
                tempB.push_back({i,j});
                cnt_T+=1;
            }
        }
    }
    
    sort(tempA.begin(),tempA.end(),cmpA);
    sort(tempB.begin(),tempB.end(),cmpB);

    
    answer.push_back(tempA[0].first);
    answer.push_back(tempB[0].second);
    answer.push_back(tempA[cnt_T-1].first+1);
    answer.push_back(tempB[cnt_T-1].second+1);

    return answer;
}
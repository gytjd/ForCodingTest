#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v;
vector<pair<int,int>> temp;

bool cmp(pair<int,int> &a,pair<int,int> &b) {
    
    if(a.second-a.first==b.second-b.first) {
        return a<b;
    }
    return a.second-a.first<b.second-b.first;
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    v.push_back(0);
    for(int i=0;i<sequence.size();i++) {
        v.push_back(sequence[i]);
    }
    for(int i=1;i<v.size();i++) {
        v[i]+=v[i-1];
    }
    
    int low=0;
    int high=1;
    
    while(low<high and high<v.size()) {
        // cout << low << " " << high << "\n";
        if(v[high]-v[low]<k) {
            high+=1;
        } else {
            if(v[high]-v[low]==k) {
                temp.push_back({low,high-1});
            }
            low+=1;
        }
    }
    

    sort(temp.begin(),temp.end(),cmp);
    answer.push_back(temp[0].first);
    answer.push_back(temp[0].second);
    
    return answer;
}
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N,C;
int temp[1004];
map<int, int> mp,mp_first;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a,pair<int, int> b) {
    if(a.first==b.first) {
        return mp_first[a.second]<mp_first[b.second];
    }
    return a.first>b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> C;
    
    for(int i=0;i<N;i++) {
        cin >> temp[i];
        mp[temp[i]]++;
        
        if(mp_first[temp[i]]==0) {
            mp_first[temp[i]]=i+1;
        }
    }
    
    for(auto it : mp) {
        v.push_back({it.second,it.first});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(auto i:v) {
        for(int j=0;j<i.first;j++) {
            cout << i.second << " ";
        }
    }
    
    return 0;
    
    
}

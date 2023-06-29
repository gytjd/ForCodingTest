#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N,M;
map<string, int> m;
vector<pair<string, int>> v;

bool cmp(pair<string, int> &a,pair<string, int> &b) {
    
    if(a.second==b.second) {
        if(a.first.size()==b.first.size()) {
            return a.first<b.first;
        }
        return a.first.size()>b.first.size();
    }
    return a.second>b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        string temp;
        cin >> temp;
        
        if(temp.size()<M) {
            continue;
        }
        
        m[temp]+=1;
    }
    
    for(pair<string, int> a:m) {
        v.push_back(a);
    }
    
    sort(v.begin(), v.end(), cmp);
  
    for(pair<string, int> temp:v) {
        cout << temp.first << "\n";
    }
    return 0;
}

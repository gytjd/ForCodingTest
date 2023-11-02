#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ret;
int N;
map<string,int> m;
vector<pair<int, int>> v;
priority_queue<int,vector<int>,less<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        m[a]=i;
    }
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        v.push_back({m[a],i});
    }
    
    sort(v.begin(), v.end());
    
    pq.push(v[0].second);
    
    for(int i=1;i<N;i++) {
        if(pq.top()>v[i].second) {
            ret+=1;
        }
        pq.push(v[i].second);
    }
    
    cout << ret << "\n";
    
    return 0;
}

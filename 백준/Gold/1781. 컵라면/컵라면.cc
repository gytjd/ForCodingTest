#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
priority_queue<int,vector<int>,greater<>> q;
int N;

bool cmp(pair<int, int> a,pair<int, int> b) {
    
    if(a.first==b.first) {
        return a.second>b.second;
    }
    return a.first<b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int start,end;
        cin >> start >> end;
        v.push_back({start,end});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int ret=0;
    for(int i=0;i<N;i++) {
        
        if(q.size()<v[i].first) {
            q.push(v[i].second);
        }
        else {
            if(q.top()<v[i].second) {
                q.pop();
                q.push(v[i].second);
            }
        }
    }
    
    while(!q.empty()) {
        ret+=q.top();
        q.pop();
    }
    cout << ret << "\n";
    
    return 0;
}

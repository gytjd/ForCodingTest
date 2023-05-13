#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


priority_queue<int,vector<int>,greater<int>> pq;
vector<pair<int, int>> v;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int start,end;
        cin >> start >> end;
        v.push_back({end,start});
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0;i<v.size();i++) {
        pq.push(v[i].second);
        if(pq.size()>v[i].first) {
            pq.pop();
        }
    }
    
    int ret=0;
    while(!pq.empty()) {
        ret+=pq.top();
        pq.pop();
    }
    
    cout << ret << "\n";
    
    return 0;
}

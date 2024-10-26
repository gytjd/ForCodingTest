#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long N;
vector<pair<long long,long long>> v[5004];
long long dist[5004];
long long visited[5004];


void Dijkstra(long long start,long long weight) {
    
    dist[start]=0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>> q;
    q.push({0,start});
    visited[start]=1;
    
    while(!q.empty()) {
        weight=q.top().first;
        start=q.top().second;
        q.pop();
        
        for(long long i=0;i<v[start].size();i++) {
            if(visited[v[start][i].second]==0 and dist[start]+v[start][i].first>dist[v[start][i].second]) {
                visited[v[start][i].second]=1;
                dist[v[start][i].second]=dist[start]+v[start][i].first;
                q.push({dist[v[start][i].second],v[start][i].second});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(long long i=0;i<N-1;i++) {
        long long startX,endX,weight;
        cin >> startX >> endX >> weight;
        v[startX].push_back({weight,endX});
        v[endX].push_back({weight,startX});
    }
    
    Dijkstra(1, 0);
    
    long long ret=0;
    for(long long i=1;i<=N;i++) {
        ret=max(ret,dist[i]);
    }
    cout << ret << "\n";
    
    return 0;
}

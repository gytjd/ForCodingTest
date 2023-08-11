#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_SIZE 100004
#define INF 1e11
using namespace std;

long long ret=INF*2;
long long N,M,K;
long long start,end_;

long long dist[MAX_SIZE][2];
vector<pair<long long, long long>> v[MAX_SIZE];

void init_() {
    for(long long i=1;i<=N;i++) {
        dist[i][0]=INF;
        dist[i][1]=INF;
    }
}

void Dijkstra(long long start,long long mode) {
    
    long long weight;
    priority_queue<pair<long long, long long>,vector<pair<long long, long long>>,greater<pair<long long, long long>>> q;
    q.push({0,start});
    dist[start][mode]=0;
    
    while(!q.empty()) {
        start=q.top().second;
        weight=q.top().first;
        q.pop();
        
        if(dist[start][0]<weight) {
            continue;
        }
        
        for(pair<long long, long long> temp:v[start]) {
            if(dist[temp.second][mode]>dist[start][mode]+temp.first) {
                dist[temp.second][mode]=dist[start][mode]+temp.first;
                q.push({dist[temp.second][mode],temp.second});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(long long i=0;i<M;i++) {
        long long S,E,W;
        cin >> S >> E >> W;
        v[S].push_back({W,E});
        v[E].push_back({W,S});
    }
    
    cin >> start >> end_;
    
    init_();
    Dijkstra(start,0);
    Dijkstra(end_,1);
    
    cin >> K;
    for(long long i=0;i<K;i++) {
        long long data;
        cin >> data;
        if(dist[data][0]!=INF and dist[data][1]!=INF) {
            ret=min(ret,dist[data][0]+dist[data][1]);
        }
    }
    
    if(ret==INF*2) {
        cout << -1 << "\n";
    }
    else {
        cout << ret << "\n";
    }
    return 0;
}

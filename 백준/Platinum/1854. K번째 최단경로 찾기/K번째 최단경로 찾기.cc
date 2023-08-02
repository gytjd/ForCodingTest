#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

struct cmp {
    bool operator()(pair<int, int> &a,pair<int, int> &b) {
        return a.second>b.second;
    }
};

int N,M,K;
vector<pair<int, int>> v[1004];
int dist[1004];
int visited[1004];

//void init_() {
//    for(int i=1;i<=N;i++) {
//        dist[i]=INF;
//    }
//}

void Dijkstra(int start) {
    
    int weight;
    priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> q;
    q.push({start,0});
    
    while(!q.empty()) {
        start=q.top().first;
        weight=q.top().second;
        q.pop();
        
        if(visited[start]==K) {
            continue;
        }
        
        dist[start]=weight;
        visited[start]+=1;
        for(pair<int, int> temp:v[start]) { // first 는 노드 번호 , second 는 가중치
            if(visited[temp.first]<K) {
                if(dist[temp.first]<dist[start]+temp.second) {
                    q.push({temp.first,dist[start]+temp.second});
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> K;
    for(int i=0;i<M;i++) {
        int s,e,w;
        cin >> s >> e >> w;
        v[s].push_back({e,w});
    }
    
//    init_();
    Dijkstra(1);
    
    for(int i=1;i<=N;i++) {
        if(visited[i]==K) {
            cout << dist[i] << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int N,M;
int S,T;
vector<pair<int,int>> v[5004];
vector<int> dist(5004,INF);

void Dijkstra(int start) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,start});
    dist[start]=0;
    
    while(!q.empty()) {
        start=q.top().second;
//        cout << q.top().first << " " << q.top().second << "\n";
        q.pop();
        
        for(pair<int,int> temp:v[start]) {
            if(dist[start]+temp.second<dist[temp.first]) {
                dist[temp.first]=dist[start]+temp.second;
                q.push({dist[temp.first],temp.first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int start,end,weight;
        cin >> start >> end >> weight;
        v[start].push_back({end,weight});
        v[end].push_back({start,weight});
    }
    cin >> S >> T;
    Dijkstra(S);
    cout << dist[T] << "\n";
    
    return 0;
}

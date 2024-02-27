#include <iostream>
#include <vector>
#include <queue>

#define INF 10000000000000
#define MAX_SIZE 100004
using namespace std;

long long N,M;
long long check[MAX_SIZE];
long long visited[MAX_SIZE];
vector<long long> dist(MAX_SIZE,INF);
vector<pair<long long,long long>> v[MAX_SIZE];

void Dijkstra(long long start) {
    
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
    dist[start]=0;
    q.push({0,start});
    
    while(!q.empty()) {
        long long weight=q.top().first;
        start=q.top().second;
        q.pop();
        
//        cout << "# " << start << " " << weight << "\n";
        
        if(dist[start]<weight) continue;
        
        for(pair<long long,long long> temp:v[start]) {
            
//            cout << temp.first << " " << temp.second << "\n";
            if(check[temp.first] and temp.first!=N-1) continue;
            
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
    for(long long i=0;i<N;i++) {
        cin >> check[i];
    }
    
    for(long long i=0;i<M;i++) {
        long long start,end,weight;
        cin >> start >> end >> weight;
        
        v[start].push_back({end,weight});
        v[end].push_back({start,weight});
    }
    
    Dijkstra(0);
    
    cout << (dist[N-1]==INF ? -1 : dist[N-1]) << "\n";

    
    return 0;
}

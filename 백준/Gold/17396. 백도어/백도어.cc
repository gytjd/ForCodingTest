#include <iostream>
#include <vector>
#include <queue>

#define INF 1e12
#define MAX_SIZE 100004
using namespace std;

long long N,M;
long long check[MAX_SIZE];
long long dist[MAX_SIZE];
long long visited[MAX_SIZE];
vector<pair<long long,long long>> v[MAX_SIZE];

struct cmp {
    bool operator()(pair<long long,long long> &a,pair<long long,long long> &b) {
        return a.second>b.second;
    }
};

void Dijkstra(long long start) {
    
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,cmp> q;
    dist[start]=0;
    q.push({start,0});
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.top().first;
        long long weight=q.top().second;
        q.pop();
        
        if(dist[start]<weight) continue;
//        cout << "# " << start << "\n";
        
        for(pair<long long,long long> temp:v[start]) {
            
//            cout << temp.first << " " << temp.second << "\n";
            
            if(dist[start]+temp.second<dist[temp.first]) {
                dist[temp.first]=dist[start]+temp.second;
                q.push({temp.first,dist[temp.first]});
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
        dist[i]=INF;
    }
    check[N-1]=0;
    
    for(long long i=0;i<M;i++) {
        long long start,end,weight;
        cin >> start >> end >> weight;
        
        if(check[start] or check[end]) continue;
        
//        cout << start << " " << end << "\n";
        
        v[start].push_back({end,weight});
        v[end].push_back({start,weight});
    }
    
    Dijkstra(0);
    
    cout << (dist[N-1]==INF ? -1 : dist[N-1]) << "\n";

    
    return 0;
}


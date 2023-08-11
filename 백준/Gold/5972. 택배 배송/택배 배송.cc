#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9
#define MAX_SIZE 500004

using namespace std;

int N,M;
int visited[MAX_SIZE];
long long dist[MAX_SIZE];
vector<pair<int, int>> arr[MAX_SIZE];

void Dijkstra(int start) {
    
    int weight;
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q;
    q.push({0,start});
    dist[start]=0;
    
    while(!q.empty()) {
        start=q.top().second;
        q.pop();
        visited[start]=1;
        
        for(pair<int, int> temp:arr[start]) {
            if(visited[temp.second]==0) {
                if(dist[temp.second]>dist[start]+temp.first) {
                    dist[temp.second]=dist[start]+temp.first;
                    q.push({dist[temp.second],temp.second});
                }
            }
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=1;i<=N;i++) {
        dist[i]=INF;
    }
    
    for(int i=0;i<M;i++) {
        int start,end,weight;
        cin >> start >> end >> weight;
        arr[start].push_back({weight,end});
        arr[end].push_back({weight,start});
    }
    
    Dijkstra(1);
    
    cout << dist[N] << "\n";
    
    return 0;
}

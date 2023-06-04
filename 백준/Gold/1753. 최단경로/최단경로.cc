#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_SIZE 987654321
using namespace std;

vector<pair<int, int>> arr[20004];
int dist[20004];
int visited[20004];
int V,E,start;

void init_() {
    for(int i=0;i<20004;i++) {
        dist[i]=MAX_SIZE;
    }
}

void Dijkstra(int start) {
    
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q;
    dist[start]=0;
    q.push({0,start});
    
    while(!q.empty()) {
        start=q.top().second;
        q.pop();
        visited[start]=1;
        
        for(pair<int, int> temp:arr[start]) {
            if(visited[temp.second]==0) {
                if(dist[start]+temp.first<dist[temp.second]) {
                    dist[temp.second]=dist[start]+temp.first;
                    q.push({dist[start]+temp.first,temp.second});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    
    cin >> V >> E;
    cin >> start;
    
    
    for(int i=0;i<E;i++) {
        int start,end,weight;
        cin >> start >> end >> weight;
        arr[start].push_back({weight,end});
    }
    
    init_();
    Dijkstra(start);
    
    for(int i=1;i<=V;i++) {
        
        if(dist[i]==MAX_SIZE) {
            cout << "INF" << "\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }
    
    return 0;
}

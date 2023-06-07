#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
#define INF 987654321

using namespace std;

int N,M,R;
vector<pair<int, int>> arr[104];
int dist[104];
int weight[104];

void init_() {
    for(int i=1;i<=N;i++) {
        dist[i]=INF;
    }
}

int display_() {
    
    int sum=0;
    for(int i=1;i<=N;i++) {
        if(dist[i]>M) {
            continue;
        }
        sum+=weight[i];
    }
    
    return sum;
}

void Dijkstra(int start) {
    
    int weight;
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q;
    q.push({0,start});
    dist[start]=0;
    
    while(!q.empty()) {
        weight=q.top().first;
        start=q.top().second;
        q.pop();
        
        
        if(dist[start]<weight) {
            continue;
        }
        
        for(pair<int, int> temp:arr[start]) {
//            cout << dist[start] << " " << temp.first << " " << dist[temp.second]  << "\n";
            if(dist[start]+temp.first<dist[temp.second]) {
                dist[temp.second]=dist[start]+temp.first;
                q.push({dist[temp.second],temp.second});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> R;
    for(int i=1;i<=N;i++) {
        cin >> weight[i];
    }
    
    for(int i=0;i<R;i++) {
        int start,end,weight;
        cin >> start >> end >> weight;
        arr[start].push_back({weight,end});
        arr[end].push_back({weight,start});
    }
    
    int ret=0;
    for(int i=1;i<=N;i++) {
        init_();
        Dijkstra(i);
        ret=max(ret,display_());
    }
    
    cout << ret << "\n";
    
    return 0;
}

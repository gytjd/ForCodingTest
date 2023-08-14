#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_SIZE 100004
#define INF 1e9+7

using namespace std;

int N,M;
vector<int> start_V;
vector<pair<int, int>> v[MAX_SIZE];
long long ret[MAX_SIZE];
long long dist[MAX_SIZE];

void init_() {
    for(int i=1;i<=N;i++) {
        dist[i]=INF;
    }
}

void display_() {
    
    cout << "\n";
    for(int i=1;i<=N;i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}
void Dijkstra(int start) {
    
    int weight;
    
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q;
    q.push({0,start});
    dist[start]=0;
    
    while(!q.empty()) {
        start=q.top().second;
        weight=q.top().first;
        q.pop();
        
        if(dist[start]<weight) {
            continue;
        }
        
        for(pair<int, int> temp:v[start]) {
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
    
    cin >> N;
    for(int i=0;i<3;i++) {
        int data;
        cin >> data;
        start_V.push_back(data);
    }
    cin >> M;
    for(int i=0;i<M;i++) {
        int S,E,W;
        cin >> S >> E >> W;
        
        v[S].push_back({W,E});
        v[E].push_back({W,S});
    }
    
    
    for(int i=1;i<=N;i++) {
        ret[i]=INF;
    }

    for(int i=0;i<3;i++) {
        init_();
        Dijkstra(start_V[i]);
        for(int j=1;j<=N;j++) {
            if(j!=start_V[0] and j!=start_V[1] and j!=start_V[2]) {
                if(dist[j]<ret[j]) {
                    ret[j]=dist[j];
                }
            }
        }
    }
    
    long long ret_Idx=0;
    long long tot=0;
    for(int i=1;i<=N;i++) {
        if(i!=start_V[0] and i!=start_V[1] and i!=start_V[2]) {
            if(tot<ret[i]) {
                tot=ret[i];
                ret_Idx=i;
            }
        }
    }
    
    cout << ret_Idx << "\n";
    
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define MAX_SIZE 100004
#define INF 1e9+7
using namespace std;

int N,M;
int X,Y,Z;
vector<pair<int, int>> v[MAX_SIZE];
int dist[MAX_SIZE];

void init_() {
    for(int i=1;i<=N;i++) {
        dist[i]=INF;
    }
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
        
        for(pair<int, int> temp:v[start]) {
            if(dist[start]+temp.first<dist[temp.second]) {
                dist[temp.second]=dist[start]+temp.first;
                q.push({dist[temp.second],temp.second});
            }
        }
    }
}

void Dijkstra_Edit(int start) {
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
        
        for(pair<int, int> temp:v[start]) {
            if(temp.second!=Y and dist[start]+temp.first<dist[temp.second]) {
                dist[temp.second]=dist[start]+temp.first;
                q.push({dist[temp.second],temp.second});
            }
        }
    }
}

void go_() {
    int temp_RetA=0;
    int temp_RetB=0;
    init_();
    Dijkstra(X);
    
    if(dist[Y]==INF) {
        temp_RetA=-1;
    }
    else {
        temp_RetA+=dist[Y];
        init_();
        Dijkstra(Y);
        if(dist[Z]==INF) {
            temp_RetA=-1;
        }
        else {
            temp_RetA+=dist[Z];
        }
    }
    
    init_();
    Dijkstra_Edit(X);
    
    if(dist[Z]==INF) {
        temp_RetB=-1;
    }
    else {
        temp_RetB=dist[Z];
    }
    
    cout << temp_RetA << " " << temp_RetB << "\n";
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<M;i++) {
        int S,E,W;
        cin >> S >> E >> W;
        v[S].push_back({W,E});
    }
    cin >> X >> Y >> Z;
    
    go_();
    
    return 0;
}

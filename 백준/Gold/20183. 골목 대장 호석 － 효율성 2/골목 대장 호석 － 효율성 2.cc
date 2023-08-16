#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_SIZE 100004
#define INF 1e9+7

using namespace std;

struct Node {
    long long weight,curr,curr_Weight;
};

struct cmp {
    bool operator()(Node &a,Node &b) {
        return a.curr_Weight>b.curr_Weight;
    }
};

long long N,M,C;
long long start_X,end_Y;
long long dist[MAX_SIZE];
vector<pair<long long, long long>> v[MAX_SIZE];
long long visited[MAX_SIZE];

void Dijkstra(long long curr) {
    long long weight,curr_Weight;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({0,curr,0});
    dist[curr]=0;
    
    while(!q.empty()) {
        weight=q.top().weight;
        curr=q.top().curr;
        curr_Weight=q.top().curr_Weight;
        q.pop();
        
        if(dist[curr]<curr_Weight) {
            continue;
        }
        
        for(pair<long long, long long> temp:v[curr]) {
            if(weight+temp.first<=C) {
                long long max_Temp=max(curr_Weight,temp.first);
                if(dist[temp.second]>max_Temp) {
                    dist[temp.second]=max_Temp;
                    q.push({weight+temp.first,temp.second,max_Temp});
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> start_X >> end_Y >> C;
    
    for(long long i=1;i<=N;i++) {
        dist[i]=INF;
    }
    
    for(long long i=0;i<M;i++) {
        long long S,E,W;
        cin >> S >> E >> W;
        v[S].push_back({W,E});
        v[E].push_back({W,S});
    }
    
    Dijkstra(start_X);
    
    if(dist[end_Y]==INF) {
        cout << -1 << "\n";
    }
    else {
        cout << dist[end_Y] << "\n";
    }
    
    return 0;
}

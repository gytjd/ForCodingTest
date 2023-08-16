#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE 5004
#define INF 1e9+7

using namespace std;

struct Node {
    int weight,curr,prev;
};

struct cmp {
    bool operator()(Node &a,Node &b) {
        return a.weight>b.weight;
    }
};

int N,M,P;
int dist[MAX_SIZE];
vector<pair<int, int>> v[MAX_SIZE];
vector<int> dir[MAX_SIZE];
int visited[MAX_SIZE];

void Dijkstra(int curr) {
    
    int weight;
    int prev=0;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({0,curr,prev});
    dist[curr]=0;
    
    while(!q.empty()) {
        weight=q.top().weight;
        curr=q.top().curr;
        prev=q.top().prev;
        q.pop();
        
        if(dist[curr]<weight) {
            continue;
        }
        
        for(pair<int, int> temp:v[curr]) {
            if(dist[curr]+temp.first<dist[temp.second]) {
                dist[temp.second]=dist[curr]+temp.first;
                dir[temp.second].clear();
                dir[temp.second].push_back(curr);
                q.push({dist[temp.second],temp.second,curr});
            }
            else if(dist[curr]+temp.first==dist[temp.second]) {
                dir[temp.second].push_back(curr);
            }
        }
    }
}

void check_P(int start) {
    
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        if(start==P) {
            cout << "SAVE HIM" << "\n";
            exit(0);
        }
        
        for(int temp:dir[start]) {
            if(visited[temp]==0) {
                visited[temp]=1;
                q.push(temp);
            }
        }
    }
    
    cout << "GOOD BYE" << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> P;
    for(int i=1;i<=N;i++) {
        dist[i]=INF;
    }
    
    for(int i=0;i<M;i++) {
        int S,E,W;
        cin >> S >> E >> W;
        v[S].push_back({W,E});
        v[E].push_back({W,S});
    }
    
    Dijkstra(1);
    check_P(N);
    
    return 0;
}

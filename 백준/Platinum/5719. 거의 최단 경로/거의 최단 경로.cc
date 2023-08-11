#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_SIZE 504
#define INF 1e9+7

using namespace std;

struct Node {
    int weight,start,prev;
};

struct cmp {
    bool operator()(Node &a,Node &b) {
        return a.weight>b.weight;
    }
};

int N,M;
int S,E;
int visited[MAX_SIZE];
int dist[MAX_SIZE];
int arr[MAX_SIZE][MAX_SIZE];
vector<int> prev_[MAX_SIZE];

void init_() {
    for(int i=0;i<N;i++) {
        dist[i]=INF;
    }
}

void Dijkstra(int start) {
    int weight,prev;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({0,start,0});
    dist[start]=0;
    
    while(!q.empty()) {
        weight=q.top().weight;
        start=q.top().start;
        prev=q.top().prev;
        q.pop();
        
        if(dist[start]<weight) {
            continue;
        }
        
        for(int i=0;i<N;i++) {
            if(arr[start][i]!=INF) {
                if(dist[i]>dist[start]+arr[start][i]) {
                    dist[i]=dist[start]+arr[start][i];
                    prev_[i].clear();
                    prev_[i].push_back(start);
                    q.push({dist[i],i,start});
                }
                else if(dist[i]==dist[start]+arr[start][i]) {
                    prev_[i].push_back(start);
                }
            }
        }
    }
}

void remove_Edge() {
    
    int start;
    queue<int> q;
    q.push(E);
    visited[E]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        for(int temp:prev_[start]) {
            arr[temp][start]=INF;
            
            if(visited[temp]==0) {
                q.push(temp);
                visited[temp]=1;
            }
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(true) {
        cin >> N >> M;
        if(N==0 and M==0) {
            break;
        }
        
        init_();
        memset(visited,0,sizeof(visited));
        for(int i=0;i<N;i++) {
            prev_[i].clear();
        }
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                arr[i][j]=INF;
            }
        }
        
        
        cin >> S >> E;
        for(int i=0;i<M;i++) {
            int start,end,weight;
            cin >> start >> end >> weight;
            arr[start][end]=min(arr[start][end],weight);
//            arr[start][end]=weight;
        }
        
        Dijkstra(S);
        
//        for(int i=0;i<N;i++) {
//            cout << i << " = ";
//            for(int temp:prev_[i]) {
//                cout << temp << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
        remove_Edge();
        init_();
        Dijkstra(S);
        
        if(dist[E]==INF) {
            cout << -1 << "\n";
        }
        else {
            cout << dist[E] << "\n";
        }
    }
    
    return 0;
}

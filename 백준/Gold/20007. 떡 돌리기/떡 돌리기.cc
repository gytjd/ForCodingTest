#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE 1004
#define INF 1e9+7

using namespace std;

int ret;
int dist[MAX_SIZE];
int N,M,X,Y;
vector<pair<int, int>> v[MAX_SIZE];

void Dijkstra(int start) {
    int weight;
    int temp_Ret=0;
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
        
        if(weight*2>X) {
            cout << -1 << "\n";
            exit(0);
        }
        else {
            if(temp_Ret+weight*2>X) {
                ret+=1;
                temp_Ret=weight*2;
            }
            else {
                temp_Ret+=weight*2;
            }
        }
        
        for(pair<int, int> temp:v[start]) {
            if(dist[start]+temp.first<dist[temp.second]) {
                dist[temp.second]=dist[start]+temp.first;
                q.push({dist[temp.second],temp.second});
            }
        }
    }
    
    cout << ret+1 << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> X >> Y;
    
    for(int i=0;i<N;i++) {
        dist[i]=INF;
    }
    
    for(int i=0;i<M;i++) {
        int S,E,W;
        cin >> S >> E >> W;
        v[S].push_back({W,E});
        v[E].push_back({W,S});
    }
    
    Dijkstra(Y);
    
    return 0;
}

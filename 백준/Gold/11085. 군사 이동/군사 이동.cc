#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_SIZE 1004
#define INF 1e9

using namespace std;

int N,M;
int C,V;
vector<pair<int, int>> v[MAX_SIZE];
int visited[MAX_SIZE];

void init_() {
    for(int i=0;i<N;i++) {
        visited[i]=0;
    }
}

void Dijkstra(int curr,int min_value) {
    int weight;
    queue<int> q;
    q.push(curr);
    visited[curr]=1;
    
    while(!q.empty()) {
        curr=q.front();
        q.pop();
        
        for(pair<int, int> temp:v[curr]) {
            if(temp.first>=min_value) {
                if(visited[temp.second]==0) {
                    visited[temp.second]=1;
                    q.push(temp.second);
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
    cin >> C >> V;
    
    for(int i=0;i<M;i++) {
        int S,E,W;
        cin >> S >> E >> W;
        v[S].push_back({W,E});
        v[E].push_back({W,S});
    }
    
    for(int i=1000;i>=1;i--) {
        init_();
        Dijkstra(C, i);
        
        if(visited[V]==1) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}

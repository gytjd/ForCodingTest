#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M,V;
vector<int> temp[10001];
int visited[10001];

void init_v() {
    int i;
    for(i=0;i<10001;i++) {
        visited[i]=0;
    }
}

void DFS_recur(int start) {
    visited[start]=1;
    cout << start << " ";
    
    for(int i=0;i<temp[start].size();i++) {
        
        if(visited[temp[start][i]]==0) {
            DFS_recur(temp[start][i]);
        }
    }
    
}

void BFS_iter(int start) {
    
    int w;
    visited[start]=1;
    
    queue<int> q;
    q.push(start);
    
    
    while(!q.empty()) {
        w=q.front();q.pop();
        cout << w << " ";
        
        for(int i=0;i<temp[w].size();i++) {
            if(visited[temp[w][i]]==0) {
                visited[temp[w][i]]=1;
                q.push(temp[w][i]);
            }
        }
    }
    
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> V;
    
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        
        temp[start].push_back(end);
        temp[end].push_back(start);
    }
    
    for(int i=1;i<=N;i++) {
        sort(temp[i].begin(),temp[i].end());
    }
    
    DFS_recur(V);
    cout << "\n";
    init_v();
    
    BFS_iter(V);
    cout << "\n";
    
    return 0;
}

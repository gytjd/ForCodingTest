#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ret;
int N,M;
vector<int> v[20004];
int visited[20004];

void BFS_iter(int start) {
    
    queue<int> q;
    q.push(start);
    visited[start]=1;
    ret=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        for(int i=0;i<v[start].size();i++) {
            if(visited[v[start][i]]==0) {
                visited[v[start][i]]=visited[start]+1;
                ret=max(visited[v[start][i]],ret);
                q.push(v[start][i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        v[start].push_back(end);
        v[end].push_back(start);
    }
    
    BFS_iter(1);
    
    for(int i=1;i<=N;i++) {
        if(ret==visited[i]) {
            cout << i << " ";
            break;
        }
    }
    
    cout << ret-1 << " ";
    
    int count_T=0;
    for(int i=1;i<=N;i++) {
        if(ret==visited[i]) {
            count_T+=1;
        }
    }
    cout << count_T << "\n";
    
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M,S,E;
int visited[300004];
vector<int> v[300004];

void go_() {
    int x,dx;
    visited[S]=1;
    queue<int> q;
    q.push(S);
    
    while(!q.empty()) {
        x=q.front();
        q.pop();
        
        if(x==E) {
            cout << visited[E]-1 << "\n";
            break;
        }
        
        dx=x+1;
        if(dx>=1 and dx<=N and visited[dx]==0) {
            visited[dx]=visited[x]+1;
            q.push(dx);
        }
        dx=x-1;
        if(dx>=1 and dx<=N and visited[dx]==0) {
            visited[dx]=visited[x]+1;
            q.push(dx);
        }
        
        for(int i=0;i<v[x].size();i++) {
            dx=v[x][i];
            if(dx>=1 and dx<=N and visited[dx]==0) {
                visited[dx]=visited[x]+1;
                q.push(dx);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    cin >> S >> E;
    for(int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    go_();
    
    return 0;
}

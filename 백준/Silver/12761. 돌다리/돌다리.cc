#include <iostream>
#include <queue>
using namespace std;

int visited[100004];

int A,B,N,M;

void go_() {
    
    int x,dx;
    visited[N]=1;
    queue<int> q;
    q.push(N);
    
    while(!q.empty()) {
        x=q.front();
        q.pop();
        
        if(x==M) {
            cout << visited[M]-1 << "\n";
            break;
        }
        
        dx=x-1;
        if(dx>=0 and dx<=100000 and visited[dx]==0) {
            visited[dx]=visited[x]+1;
            q.push(dx);
        }
        dx=x+1;
        if(dx>=0 and dx<=100000 and visited[dx]==0) {
            visited[dx]=visited[x]+1;
            q.push(dx);
        }
        dx=x+A;
        if(dx>=0 and dx<=100000 and visited[dx]==0) {
            visited[dx]=visited[x]+1;
            q.push(dx);
        }
        dx=x-A;
        if(dx>=0 and dx<=100000 and visited[dx]==0) {
            visited[dx]=visited[x]+1;
            q.push(dx);
        }
        dx=x+B;
        if(dx>=0 and dx<=100000 and visited[dx]==0) {
            visited[dx]=visited[x]+1;
            q.push(dx);
        }
        dx=x-B;
        if(dx>=0 and dx<=100000 and visited[dx]==0) {
            visited[dx]=visited[x]+1;
            q.push(dx);
        }
        dx=x*A;
        if(dx>=0 and dx<=100000 and visited[dx]==0) {
            visited[dx]=visited[x]+1;
            q.push(dx);
        }
        dx=x*B;
        if(dx>=0 and dx<=100000 and visited[dx]==0) {
            visited[dx]=visited[x]+1;
            q.push(dx);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> A >> B >> N >> M;
    
    go_();
    
    return 0;
}

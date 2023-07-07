#include <iostream>
#include <queue>
using namespace std;

int F,S,G,U,D;
int visited[1000004];

void go_(int start) {
    
    int dx;
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        dx=start+U;
        
        if(dx>=1 and dx<=F) {
            if(visited[dx]==0) {
                visited[dx]=visited[start]+1;
                q.push(dx);
            }
        }
        
        dx=start-D;
        
        if(dx>=1 and dx<=F) {
            if(visited[dx]==0) {
                visited[dx]=visited[start]+1;
                q.push(dx);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> F >> S >> G >> U >> D;
    
    go_(S);
    if(visited[G]) {
        cout << visited[G]-1 << "\n";
    }
    else {
        cout << "use the stairs" << "\n";
    }
    
    return 0;
}

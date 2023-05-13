#include <iostream>
#include <queue>
using namespace std;

int visited[100001];
int N,K;

void BFS_iter(int start) {
    
    int w;
    visited[start]=1;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        w=q.front();q.pop();
        
        if(w==K) {
            break;
        }
        
        if(w-1>=0 and visited[w-1]==0) {
            q.push(w-1);
            visited[w-1]=visited[w]+1;
        }
        
        if(w+1<100001 and visited[w+1]==0) {
            q.push(w+1);
            visited[w+1]=visited[w]+1;
        }
        
        if(2*w<100001 and visited[2*w]==0) {
            q.push(2*w);
            visited[2*w]=visited[w]+1;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    
    BFS_iter(N);
    cout << visited[K]-1 << "\n";
    
    return 0;
}

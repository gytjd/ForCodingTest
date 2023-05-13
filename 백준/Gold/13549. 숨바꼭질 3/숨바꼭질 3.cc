#include <iostream>
#include <queue>

using namespace std;

int N,M;
int visited[200001];

void BFS_iter(int start) {
    
    visited[start]=1;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        if(start==M) {
            cout << visited[M]-1 << "\n";
            break;
        }
        
        if(start*2<=200000) {
            if(visited[2*start]<=200000) {
                visited[2*start]=visited[start];
                q.push(2*start);
            }
        }
        
        if(start-1>=0) {
            if(visited[start-1]==0) {
                visited[start-1]=visited[start]+1;
                q.push(start-1);
            }
        }
        
        if(start+1<=200000) {
            if(visited[start+1]==0) {
                visited[start+1]=visited[start]+1;
                q.push(start+1);
            }
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    BFS_iter(N);
    
    return 0;
}

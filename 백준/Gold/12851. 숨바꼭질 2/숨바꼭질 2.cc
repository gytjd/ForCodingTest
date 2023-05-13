#include <iostream>
#include <queue>
using namespace std;

int N,M;
int visited[200001];
int count_v[200001];

void BFS_iter(int start) {
    
    visited[start]=1;
    count_v[start]=1;
    
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        if(start-1>=0) {
            if(visited[start-1]==0) {
                visited[start-1]=visited[start]+1;
                count_v[start-1]=count_v[start];
                q.push(start-1);
            }
            else if(visited[start-1]==visited[start]+1) {
                count_v[start-1]+=count_v[start];
            }
        }
    
        if(start+1<=200000) {
            if(visited[start+1]==0) {
                visited[start+1]=visited[start]+1;
                count_v[start+1]=count_v[start];
                q.push(start+1);
            }
            else if(visited[start+1]==visited[start]+1) {
                count_v[start+1]+=count_v[start];
            }
        }
        
        if(2*start<=200000) {
            if(visited[2*start]==0) {
                visited[2*start]=visited[start]+1;
                count_v[2*start]=count_v[start];
                q.push(2*start);
            }
            else if(visited[2*start]==visited[start]+1) {
                count_v[2*start]+=count_v[start];
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
    cout << visited[M]-1 << "\n";
    cout << count_v[M] << "\n";
    
    return 0;
}

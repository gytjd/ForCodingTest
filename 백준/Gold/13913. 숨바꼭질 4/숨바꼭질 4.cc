#include <iostream>
#include <queue>
using namespace std;

int N,M;
int visited[200001];
int parent[200001];

void BFS_iter(int start) {
    visited[start]=1;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        if(start==M) {
            vector<long long> v;
            v.push_back(M);
            
            int temp=M;
            while(temp!=N) {
                v.push_back(parent[temp]);
                temp=parent[temp];
            }
            
            cout << visited[M]-1 << "\n";
            
            for(long long i=v.size()-1;i>=0;i--) {
                cout << v[i] << " ";
            }
            
            cout << "\n";
            break;
        }
        
        if(start-1>=0) {
            if(visited[start-1]==0) {
                visited[start-1]=visited[start]+1;
                parent[start-1]=start;
                q.push(start-1);
            }
        }
        
        if(start+1<=200000) {
            if(visited[start+1]==0) {
                visited[start+1]=visited[start]+1;
                parent[start+1]=start;
                q.push(start+1);
            }
        }
        
        if(start*2<=200000) {
            if(visited[2*start]==0) {
                visited[2*start]=visited[start]+1;
                parent[2*start]=start;
                q.push(2*start);
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

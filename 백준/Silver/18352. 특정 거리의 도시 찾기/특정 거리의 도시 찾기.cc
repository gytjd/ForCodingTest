#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M,K,X;

vector<int> arr[300004];
int dist[300004];
int visited[300004];

void display_() {
    
    bool check_Flag=false;
    for(int i=1;i<=N;i++) {
        if(dist[i]==K) {
            check_Flag=true;
            cout << i << "\n";
        }
    }
    
    if(!check_Flag) {
        cout << -1 << "\n";
    }
}
void BFS_iter(int start) {
    queue<int> q;
    q.push(start);
    dist[start]=0;
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        for(int temp:arr[start]) {
            if(visited[temp]==0) {
                visited[temp]=1;
                dist[temp]=dist[start]+1;
                q.push(temp);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> K >> X;
    
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        arr[start].push_back(end);
    }
    
    BFS_iter(X);
    display_();
    
    return 0;
    
}

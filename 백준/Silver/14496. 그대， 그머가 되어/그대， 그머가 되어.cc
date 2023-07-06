#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int A,B;
int N,M;
vector<int> arr[1004];
int visited[1004];

void BFS_iter(int start) {
    
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        for(int i=0;i<arr[start].size();i++) {
            if(visited[arr[start][i]]==0) {
                visited[arr[start][i]]=visited[start]+1;
                q.push(arr[start][i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> A >> B;
    cin >> N >> M;
    
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        
        arr[start].push_back(end);
        arr[end].push_back(start);
    }
    
    BFS_iter(A);
    
    cout << visited[B]-1 << "\n";
    
    return 0;
}

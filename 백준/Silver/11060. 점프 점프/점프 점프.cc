#include <iostream>
#include <queue>
#define MAX_SIZE 1004

using namespace std;

int N;
int arr[MAX_SIZE];
int visited[MAX_SIZE];

void BFS_iter(int start) {
    
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        for(int i=start;i<=start+arr[start];i++) {
            if(visited[i]==0 and i<N) {
                visited[i]=visited[start]+1;
                q.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    BFS_iter(0);
    
    int ret=visited[N-1]==0?-1:visited[N-1]-1;
    cout << ret << "\n";
    
    return 0;
}

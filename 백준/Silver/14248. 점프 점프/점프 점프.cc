#include <iostream>
#include <queue>
using namespace std;

int arr[100004];
int visited[100004];

int N,M;
int ret;

void go_() {
    int x,dx;
    queue<int> q;
    q.push(M);
    visited[M]=1;
    ret+=1;
    
    while(!q.empty()) {
        x=q.front();
        q.pop();
        
        dx=x+arr[x];
        if(dx>=1 and dx<=N and visited[dx]==0) {
            visited[dx]=1;
            ret+=1;
            q.push(dx);
        }
        dx=x-arr[x];
        if(dx>=1 and dx<=N and visited[dx]==0) {
            visited[dx]=1;
            ret+=1;
            q.push(dx);
        }
    }
    
    cout << ret << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> arr[i];
    }
    cin >> M;
    
    go_();
    
    return 0;
}

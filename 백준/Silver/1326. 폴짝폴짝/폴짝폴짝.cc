#include <iostream>
#include <queue>

using namespace std;

int N;
int start,end_;
int arr[10004];
int visited[10004];

void go_(int start) {
    
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        for(int i=start;i<=N;i+=arr[start]) {
            if(visited[i]==0) {
                q.push(i);
                visited[i]=visited[start]+1;
            }
        }
        
        for(int i=start;i>=1;i-=arr[start]) {
            if(visited[i]==0) {
                q.push(i);
                visited[i]=visited[start]+1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=1;i<=N;i++) {
        cin >> arr[i];
    }
    cin >> start >> end_;
    
    go_(start);
//    for(int i=1;i<=N;i++) {
//        cout << visited[i] << " ";
//    }
//    cout << "\n";
//    
    cout << ((!visited[end_]) ? -1 : (visited[end_] - 1)) << "\n";

    
    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

int visited[1000004];

void BFS_iter(int start) {
    
    visited[start]=0;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        start=q.front();
        q.pop();
        
//        cout << start << "\n";
        
        if(start%3==0 and visited[start/3]==0 and start/3>=1)
        {
            q.push(start/3);
            visited[start/3]=visited[start]+1;
        }
        if(start%2==0 and visited[start/2]==0 and start/2>=1)
        {
            q.push(start/2);
            visited[start/2]=visited[start]+1;
        }
        
        if(visited[start-1]==0 and start-1>=1) {
            q.push(start-1);
            visited[start-1]=visited[start]+1;
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int start;
    cin >> start;
    
    BFS_iter(start);
    cout << visited[1] << "\n";
    
    return 0;
}

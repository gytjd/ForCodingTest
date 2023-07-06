#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N,M,K;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[104][104];
int visited[104][104];

void display_() {
    
    cout << "\n";
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
int BFS_iter(int x,int y) {
    
    int ret=0;
    int dx,dy;
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        ret+=1;
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<=0 or dx>N or dy<=0 or dy>M) {
                continue;
            }
            
            if(visited[dx][dy]==0 and arr[dx][dy]==1) {
                visited[dx][dy]=1;
                q.push({dx,dy});
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> K;
    
    for(int i=0;i<K;i++) {
        int start,end;
        cin >> start >> end;
        arr[start][end]=1;
    }
    
    
    int ret=0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(visited[i][j]==0 and arr[i][j]==1) {
                ret=max(ret,BFS_iter(i, j));
            }
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}

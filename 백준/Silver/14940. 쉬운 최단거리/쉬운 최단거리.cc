#include <iostream>
#include <queue>
using namespace std;

int N,M;
int arr[1004][1004];
int visited[1004][1004];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

void display_() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            
            if(visited[i][j]==0 and arr[i][j]==1) {
                cout << -1 << " ";
            }
            else if(visited[i][j]==0) {
                cout << 0 << " ";
            }
            else {
                cout << visited[i][j]-1 << " ";
            }
        }
        cout << "\n";
    }
}

void BFS_iter(int x,int y) {
    
    int dx,dy;
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(visited[dx][dy]==0 and arr[dx][dy]==1) {
                visited[dx][dy]=visited[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    
    int startX,startY;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            
            if(arr[i][j]==2) {
                startX=i;
                startY=j;
            }
        }
    }
    
    BFS_iter(startX, startY);
    display_();
    
    return 0;
}

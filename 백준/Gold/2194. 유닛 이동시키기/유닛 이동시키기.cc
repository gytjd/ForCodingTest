#include <iostream>
#include <queue>
using namespace std;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int startX,startY;
int endX,endY;
int N,M,A,B,K;
int arr[504][504];
int visited[504][504];

int is_check(int x,int y) {
    for(int i=x;i<x+A;i++) {
        for(int j=y;j<y+B;j++) {
            if(i>N or j>M or arr[i][j]==1) {
                return 0;
            }
        }
    }
    
    return 1;
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
            
            if(dx<=0 or dx>N or dy<=0 or dy>M) {
                continue;
            }
            
            if(visited[dx][dy]==0 and arr[dx][dy]==0 and is_check(dx, dy)) {
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
    
    cin >> N >> M >> A >> B >> K;
    
    for(int i=0;i<K;i++) {
        int start,end;
        cin >> start >> end;
        arr[start][end]=1;
    }
    
    cin >> startX >> startY;
    cin >> endX >> endY;
    
    BFS_iter(startX, startY);
    
    if(visited[endX][endY]==0) {
        cout << -1 << "\n";
    }
    else {
        cout << visited[endX][endY]-1 << "\n";
    }
    
    return 0;
}

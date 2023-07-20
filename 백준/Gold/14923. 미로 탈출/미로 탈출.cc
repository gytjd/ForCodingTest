#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int x,y,d;
};

int N,M;
int startX,startY;
int endX,endY;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[1004][1004];
int visited[1004][1004][2];

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

void BFS_iter(int x,int y,int d) {
    int dx,dy;
    queue<Node> q;
    q.push({x,y,d});
    visited[x][y][d]=1;
    
    while(!q.empty()) {
        x=q.front().x;
        y=q.front().y;
        d=q.front().d;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(visited[dx][dy][d]==0) {
                if(arr[dx][dy]==1 and d==0) {
                    visited[dx][dy][1]=visited[x][y][d]+1;
                    q.push({dx,dy,1});
                }
                else if(arr[dx][dy]==0) {
                    visited[dx][dy][d]=visited[x][y][d]+1;
                    q.push({dx,dy,d});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    cin >> startX >> startY;
    cin >> endX >> endY;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }
    
    BFS_iter(startX-1, startY-1, 0);
    if(visited[endX-1][endY-1][0] or visited[endX-1][endY-1][1]) {
        if(visited[endX-1][endY-1][0] and visited[endX-1][endY-1][1]) {
            cout << min(visited[endX-1][endY-1][0]-1,visited[endX-1][endY-1][1]-1) << "\n";
        }
        else if(visited[endX-1][endY-1][0]) {
            cout << visited[endX-1][endY-1][0]-1 << "\n";
        }
        else if(visited[endX-1][endY-1][1]) {
            cout << visited[endX-1][endY-1][1]-1 << "\n";
        }
    }
    else {
        cout << -1 << "\n";
    }
    
    return 0;
}



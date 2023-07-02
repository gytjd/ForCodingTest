#include <iostream>
#include <queue>
using namespace std;

int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[1004][1004];
int visited[1004][1004];

int H,W,Sr,Sc,Fr,Fc;

void display_() {
    
    cout << "\n";
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

int is_check(int x,int y) {
    
    for(int i=x;i<x+H;i++) {
        if(arr[i][y]==1 or arr[i][y+W-1]==1) {
            return 0;
        }
    }
    
    for(int i=y;i<y+W;i++) {
        if(arr[x][i]==1 or arr[x+H-1][i]==1) {
            return 0;
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
            
            if(dx>0 and dx+H<=N+1 and dy>0 and dy+W<=M+1) {
                if(is_check(dx, dy) and visited[dx][dy]==0) {
                    visited[dx][dy]=visited[x][y]+1;
                    q.push({dx,dy});
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
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin >> arr[i][j];
        }
    }
    
    cin >> H >> W >> Sr >> Sc >> Fr >> Fc;
    
    BFS_iter(Sr, Sc);
    
    if(visited[Fr][Fc]==0) {
        cout << -1 << "\n";
    }
    else {
        cout << visited[Fr][Fc]-1 << "\n";
    }
    
    return 0;
}

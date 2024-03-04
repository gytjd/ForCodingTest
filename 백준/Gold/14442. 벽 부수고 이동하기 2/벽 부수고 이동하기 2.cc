#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int x,y,d;
};

int N,M,K;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[1004][1004];
int visited[14][1004][1004];

void display_() {
    for(int i=0;i<=K;i++) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<M;k++) {
                cout << visited[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
}

void BFS_iter(int x,int y,int d) {
    
    int dx,dy;
    queue<Node> q;
    q.push({x,y,d});
    visited[d][x][y]=1;
    
    while(!q.empty()) {
        x=q.front().x;
        y=q.front().y;
        d=q.front().d;
        q.pop();
        
//        cout << d << " " << x << " " << y << "\n";
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(visited[d][dx][dy]==0 and arr[dx][dy]==0) {
                visited[d][dx][dy]=visited[d][x][y]+1;
                q.push({dx,dy,d});
            }
            
            if(visited[d+1][dx][dy]==0 and arr[dx][dy]==1 and d<K) {
                visited[d+1][dx][dy]=visited[d][x][y]+1;
                q.push({dx,dy,d+1});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        for(int j=0;j<M;j++) {
            arr[i][j]=a[j]-'0';
        }
    }
    
    BFS_iter(0, 0, 0);
//    display_();
    
    int answer=987654321;
    for(int i=0;i<=K;i++) {
        if(visited[i][N-1][M-1]!=0) {
            answer=min(answer,visited[i][N-1][M-1]);
        }
    }
    
    cout << (answer==987654321?-1:answer) << "\n";
    
    return 0;
}

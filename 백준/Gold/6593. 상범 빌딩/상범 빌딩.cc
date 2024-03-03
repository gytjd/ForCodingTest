#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Node {
    int z,x,y;
};

int L,R,C;
int dir[6][3]={{0,0,1},{0,1,0},{0,0,-1},{0,-1,0},{1,0,0},{-1,0,0}};
char arr[34][34][34];
int visited[34][34][34];
Node start;
Node end_;

void BFS_iter(int z,int x,int y) {
    
    int dz,dx,dy;
    queue<Node> q;
    q.push({z,x,y});
    visited[z][x][y]=1;
    
    while(!q.empty()) {
        z=q.front().z;
        x=q.front().x;
        y=q.front().y;
        q.pop();
        
        for(int i=0;i<6;i++) {
            dz=z+dir[i][0];
            dx=x+dir[i][1];
            dy=y+dir[i][2];
            
            if(dx<0 or dx>=R or dy<0 or dy>=C or dz<0 or dz>=L or arr[dz][dx][dy]=='#') {
                continue;
            }
            
            if(visited[dz][dx][dy]==0) {
                visited[dz][dx][dy]=visited[z][x][y]+1;
                q.push({dz,dx,dy});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(true) {
        cin >> L >> R >> C;
        if(!L and !R and !C) break;
        
        memset(visited,0,sizeof(visited));
        
        for(int i=0;i<L;i++) {
            for(int j=0;j<R;j++) {
                for(int k=0;k<C;k++) {
                    cin >> arr[i][j][k];
                    if(arr[i][j][k]=='S') {
                        start.z=i;
                        start.x=j;
                        start.y=k;
                    }
                    
                    if(arr[i][j][k]=='E') {
                        end_.z=i;
                        end_.x=j;
                        end_.y=k;
                    }
                }
            }
        }
        
        BFS_iter(start.z, start.x, start.y);
        
        if(visited[end_.z][end_.x][end_.y]==0) {
            cout << "Trapped!" << "\n";
        }
        else {
            cout << "Escaped in " << visited[end_.z][end_.x][end_.y]-1 << " minute(s)." << "\n";
        }
    }
    
    return 0;
}

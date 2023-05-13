#include <iostream>
#include <queue>
using namespace std;

int N,M;
int temp[1001][1001];
int visited[1001][1001];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};


int BFS_iter() {
    
    int cnt=0;
    int x,y;
    int dx,dy;
    
    queue<pair<int, int>> q;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(temp[i][j]==1) {
                q.push(make_pair(i, j));
                visited[i][j]=1;
                cnt=1;
            }
        }
    }
    
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
            
            if(visited[dx][dy]==0 and temp[dx][dy]==0) {
                visited[dx][dy]=visited[x][y]+1;
                
                if(visited[dx][dy]>cnt) {
                    cnt=visited[dx][dy];
                }
                q.push(make_pair(dx, dy));
            }
        }
    }
    
    
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(visited[i][j]==0 and temp[i][j]==0) {
                return -1;
            }
        }
    }
    return cnt-1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> M >> N;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> temp[i][j];
        }
    }
    
    cout << BFS_iter() << "\n";
    
    return 0;
}

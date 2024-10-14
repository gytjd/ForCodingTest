#include <vector>
#include <queue>

using namespace std;

int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[104][104];
int visited[104][104];

void BFS_iter(int x,int y) {
    int dx,dy;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M or arr[dx][dy]==0) {
                continue;
            }
            
            if(visited[dx][dy]==0) {
                visited[dx][dy]=visited[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    N=maps.size();
    M=maps[0].size();
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            arr[i][j]=maps[i][j];
        }
    }
    
    BFS_iter(0,0);
    
    if(visited[N-1][M-1]) {
        return visited[N-1][M-1];
    }
    else {
        return -1;
    }
}
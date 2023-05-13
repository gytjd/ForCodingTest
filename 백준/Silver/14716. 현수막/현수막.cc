#include <iostream>
#include <queue>
using namespace std;

int arr[254][254];
int visited[254][254];

int N,M;
int dir[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}};

void BFS_iter(int x,int y) {
    
    int dx,dy;
    visited[x][y]=1;
    queue<pair<int, int >> q;
    
    q.push(make_pair(x, y));
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<8;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(arr[dx][dy]==1 and visited[dx][dy]==0) {
                visited[dx][dy]=1;
                q.push(make_pair(dx, dy));
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }
    
    int count_T=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr[i][j]==1 and visited[i][j]==0) {
                BFS_iter(i,j);
                count_T+=1;
            }
        }
    }
    
    cout << count_T << "\n";
    
    return 0;
}

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int arr[1004][1004];
int visited[1004][1004];
queue<pair<int,int>> q;

int cal_ret() {
    
    int max_Ret=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(visited[i][j]==0 and arr[i][j]==0) {
                return -1;
            }
            max_Ret=max(max_Ret,visited[i][j]);
        }
    }
    return max_Ret-1;
}
void BFS_iter() {
    int x,y;
    int dx,dy;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M or arr[dx][dy]==-1) {
                continue;;
            }
            
            if(visited[dx][dy]==0) {
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
    
    cin >> M >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            
            cin >> arr[i][j];
            if(arr[i][j]==1) {
                visited[i][j]=1;
                q.push({i,j});
            }
        }
    }
    
    BFS_iter();
    cout << cal_ret() << "\n";
    
    return 0;
}

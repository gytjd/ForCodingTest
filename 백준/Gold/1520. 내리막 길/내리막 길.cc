#include <iostream>
#include <queue>
using namespace std;

int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[504][504];
int visited[504][504];

void display_() {
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}
int BFS_recur(int x,int y) {
    int dx,dy;
    if(visited[x][y]!=-1) {
        return visited[x][y];
    }
    
    if(x==N-1 and y==M-1) {
        return 1;
    }
    
    visited[x][y]=0;
    for(int i=0;i<4;i++) {
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        
        if(dx<0 or dx>=N or dy<0 or dy>=M) {
            continue;
        }
        
        if(arr[x][y]>arr[dx][dy]){
            visited[x][y]+=BFS_recur(dx, dy);
        }
    }
    
//    display_();
    
    return visited[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            visited[i][j]=-1;
        }
    }
    
    cout << BFS_recur(0, 0) << "\n";
    
    return 0;
}

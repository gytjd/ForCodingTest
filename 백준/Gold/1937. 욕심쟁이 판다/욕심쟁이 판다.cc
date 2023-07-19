#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[504][504];
long long visited[504][504];

long long DFS_recur(int x,int y) {
    
    int dx,dy;
    
    if(visited[x][y]!=-1) {
        return visited[x][y];
    }
    visited[x][y]=1;
    for(int i=0;i<4;i++) {
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        
        if(dx<0 or dx>=N or dy<0 or dy>=N) {
            continue;
        }
        
        if(arr[dx][dy]>arr[x][y])
            visited[x][y]=max(DFS_recur(dx, dy)+1,visited[x][y]);
    }
    
    return visited[x][y];
}

void go_() {
    
    long long ret=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            ret=max(ret,DFS_recur(i, j));
        }
    }
    
    cout << ret << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    memset(visited, -1, sizeof(visited));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }
    
    go_();
    
    return 0;
}

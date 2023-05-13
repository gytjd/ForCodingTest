#include <iostream>
using namespace std;

int arr[14][14];
int visited[14][14];

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int N;
int min_N=987654321;

int is_check(int x,int y) {
    
    if(visited[x][y]==1) {
        return 0;
    }
    
    int dx,dy;
    
    for(int i=0;i<4;i++) {
        
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        
        if(visited[dx][dy]==1) {
            return 0;
        }
    }
    
    return 1;
}

void is_rollback(int x,int y) {
    
    int dx,dy;
    visited[x][y]=0;
    
    for(int i=0;i<4;i++) {
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        visited[dx][dy]=0;
    }
}

int BFS_iter(int x,int y) {
    
    int dx,dy;
    int result=arr[x][y];
    
    visited[x][y]=1;
    
    for(int i=0;i<4;i++) {
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        
        result+=arr[dx][dy];
        visited[dx][dy]=1;
    }
    
    return result;
}


void DFS_recur(int depth,int sum) {
    
    if(depth==3) {
        if(min_N>sum) {
            min_N=sum;
        }
        return;
    }
    
    for(int i=1;i<N-1;i++) {
        for(int j=1;j<N-1;j++) {
            
            if(is_check(i, j)==1) {
                DFS_recur(depth+1, sum+BFS_iter(i, j));
                is_rollback(i, j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }
    
    DFS_recur(0, 0);
    
    cout << min_N << "\n";
    
    return 0;
}

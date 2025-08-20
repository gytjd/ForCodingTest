#include <iostream>

using namespace std;

int N,M;
int ret;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char arr[24][24];
int check[34];

void DFS_recur(int curr,int x,int y) {
    
    ret=max(ret,curr);
    
    int dx,dy;
    for(int i=0;i<4;i++) {
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        
        if(dx<0 or dx>=N or dy<0 or dy>=M) {
            continue;
        }
        
        if(check[arr[dx][dy]-65]==0) {
            check[arr[dx][dy]-65]=1;
            DFS_recur(curr+1, dx, dy);
            check[arr[dx][dy]-65]=0;
        }
        
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        string data;
        cin >> data;
        
        for(int j=0;j<M;j++) {
            arr[i][j]=data[j];
        }
    }
    
    check[arr[0][0]-65]=1;
    DFS_recur(0, 0, 0);
    
    cout << ret+1 << "\n";
    
    return 0;
}

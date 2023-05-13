#include <iostream>
#include <queue>

struct Node {
    int x;
    int y;
    
    Node() {
        x=0;
        y=0;
    }
    
    Node(int dx,int dy) {
        x=dx;
        y=dy;
    }
};

using namespace std;

int temp[104][104];
int visited[104][104];

int N,M;

int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

void find_Maze(int x,int y) {
    
    int i;
    Node q;
    queue<Node> result;
    result.push(Node(x,y));
    visited[x][y]=1;
    
    while(!result.empty()) {
        q=result.front();
        result.pop();
        
        int dx,dy;
        x=q.x;
        y=q.y;
    
        
        for(i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N+1 or dy<0 or dy>=M+1) {
                continue;
            }
            
            if(visited[dx][dy]==0 and temp[dx][dy]==1) {
                temp[dx][dy]=temp[x][y]+1;
                visited[dx][dy]=1;
                result.push(Node(dx,dy));
            }
        }
    }
    
}
int main() {
    
    int i,j;
    
    scanf("%d %d",&N,&M);
    
    for(i=1;i<=N;i++) {
        for(j=1;j<=M;j++) {
            scanf("%1d",&temp[i][j]);
        }
    }
    
    find_Maze(1, 1);
    
    printf("%d\n",temp[N][M]);
    
    return 0;
    
}

#include <iostream>
#include <vector>
using namespace std;

int visited[9][9];
int R,C,K;

vector<string> arr;
int x1,y1,x2,y2;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int tot;

void DFS_recur(int x,int y,int depth) {
    
    int dx,dy;
    
    if(x==x2 and y==y2) {
        
        if(depth==K-1) {
            tot+=1;
        }
        return;
    }
    
    for(int i=0;i<4;i++) {
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        
        if(dx<0 or dx>=R or dy<0 or dy>=C) {
            continue;
        }
        
        if(arr[dx][dy]=='.' and visited[dx][dy]==0) {
            visited[dx][dy]=1;
            DFS_recur(dx, dy,depth+1);
            visited[dx][dy]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> R >> C >> K;
    x1=R-1; y1=0;
    x2=0; y2=C-1;
    
    for(int i=0;i<R;i++) {
        string a;
        cin >> a;
        arr.push_back(a);
    }
    
    visited[x1][y1]=1;
    DFS_recur(x1, y1,0);
    
    cout << tot << "\n";
    
    return 0;
}


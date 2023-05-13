#include <iostream>
#include <queue>
using namespace std;

int temp[50][50];
int visited[50][50];
int N,M,K;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

void init_() {
    int i,j;
    for(i=0;i<50;i++) {
        for(j=0;j<50;j++) {
            temp[i][j]=0;
            visited[i][j]=0;
        }
    }
}

void BFS_iter(int x,int y) {
    
    int dx,dy;
    visited[x][y]=1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
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
            
            if(visited[dx][dy]==0 and temp[dx][dy]==1) {
                visited[dx][dy]=1;
                q.push(make_pair(dx, dy));
            }
        }
    }
        
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++) {
        
        init_();
        cin >> M >> N >> K;
        
        for(int j=0;j<K;j++) {
            int start,end;
            cin >> start >> end;
            temp[end][start]=1;
        }
        
        
        int count=0;
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(temp[i][j]==1 and visited[i][j]==0) {
                    BFS_iter(i, j);
                    count+=1;
                }
            }
        }
        
        cout << count << "\n";
    }
    
    
    return 0;
}

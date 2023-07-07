#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int T;
int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char arr[104][104];
int visited[104][104];

void go_(int x,int y) {
    int dx,dy;
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
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
            
            if(visited[dx][dy]==0 and arr[dx][dy]=='#') {
                visited[dx][dy]=1;
                q.push({dx,dy});
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    
    for(int i=0;i<T;i++) {
        cin >> N >> M;
        memset(visited, 0, sizeof(visited));
        
        for(int j=0;j<N;j++) {
            string a;
            cin >> a;
            for(int k=0;k<M;k++) {
                arr[j][k]=a[k];
            }
        }
        
        int ret=0;
        for(int j=0;j<N;j++) {
            for(int k=0;k<M;k++) {
                if(visited[j][k]==0 and arr[j][k]=='#') {
                    go_(j, k);
                    ret+=1;
                }
            }
        }
        
        cout << ret << "\n";
    }
    
    return 0;
}

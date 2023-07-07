#include <iostream>
#include <queue>
using namespace std;

int N,M;
int startX,startY;
int dir[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int arr[504][504];
int visited[504][504];

void BFS_iter(int x,int y) {
    int dx,dy;
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<8;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<=0 or dx>N or dy<=0 or dy>N) {
                continue;
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
    
    cin >> N >> M;
    cin >> startX >> startY;
    BFS_iter(startX, startY);
    
    for(int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        cout << visited[a][b]-1 << " ";
    }
    cout << "\n";
    return 0;
}

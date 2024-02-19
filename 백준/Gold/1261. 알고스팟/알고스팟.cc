#include <iostream>
#include <deque>

using namespace std;

int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[104][104];
int visited[104][104];
deque<pair<int, int>> dq;

void BFS_iter(int x,int y) {
    
    int dx,dy;
    visited[x][y]=1;
    dq.push_back({x,y});
    
    while(!dq.empty()) {
        x=dq.front().first;
        y=dq.front().second;
        dq.pop_front();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(visited[dx][dy]==0) {
                if(arr[dx][dy]==0) {
                    visited[dx][dy]=visited[x][y];
                    dq.push_front({dx,dy});
                }
                else {
                    visited[dx][dy]=visited[x][y]+1;
                    dq.push_back({dx,dy});
                }
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
        string a;
        cin >> a;
        for(int j=0;j<M;j++) {
            arr[i][j]=a[j]-'0';
        }
    }
    
    BFS_iter(0, 0);
    cout << visited[N-1][M-1]-1 << "\n";
    
    return 0;
}

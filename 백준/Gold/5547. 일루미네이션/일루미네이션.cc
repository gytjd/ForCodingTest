#include <iostream>
#include <queue>
using namespace std;

int N,M;
int arr[104][104];
int visited[104][104];

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dir_O[6][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{0,-1}};
int dir_E[6][2]={{-1,0},{0,1},{1,0},{1,-1},{0,-1},{-1,-1}};

void display_() {
    
    cout << "\n";
    for(int i=0;i<=N+1;i++) {
        for(int j=0;j<=M+1;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}


void BFS_iter(int x,int y) {
    int dx,dy;
    int ret=0;
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        if(x%2==0) {
            
            for(int i=0;i<6;i++) {
                dx=x+dir_E[i][0];
                dy=y+dir_E[i][1];
                
                if(dx<0 or dx>N+1 or dy<0 or dy>M+1) {
                    continue;
                }
                
                
                if(arr[dx][dy]==0 and visited[dx][dy]==0) {
                    visited[dx][dy]=1;
                    q.push({dx,dy});
                }
                else if(arr[dx][dy]==1) {
                    ret+=1;
                }
            }
        }
        else {
            
            for(int i=0;i<6;i++) {
                dx=x+dir_O[i][0];
                dy=y+dir_O[i][1];
                
                if(dx<0 or dx>N+1 or dy<0 or dy>M+1) {
                    continue;
                }
                
                if(arr[dx][dy]==0 and visited[dx][dy]==0) {
                    visited[dx][dy]=1;
                    q.push({dx,dy});
                }
                else if(arr[dx][dy]==1) {
                    ret+=1;
                }
            }
        }
    }
    
    cout << ret << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> M >> N;
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin >> arr[i][j];
        }
    }
    
    BFS_iter(0, 0);
    
    return 0;
}

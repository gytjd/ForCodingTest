#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M;
int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int arr[54][54];
int visited[54][54];
int ret;
queue<pair<int, int>> q;

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}
void BFS_iter() {
    
    int x,y;
    int dx,dy;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<8;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(visited[dx][dy]==0) {
                visited[dx][dy]=visited[x][y]+1;
                q.push({dx,dy});
                ret=max(ret,visited[dx][dy]);
            }
        }
    }
    
//    display_();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            if(arr[i][j]) {
                visited[i][j]=1;
                q.push({i,j});
            }
        }
    }
    
    BFS_iter();
    
    
    cout << ret-1 << "\n";
    
    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

int N;
int dir[2][2]={{0,1},{1,0}};
int arr[68][68];
int visited[68][68];

void BFS_iter(int x,int y) {
    int dx,dy;
    visited[x][y]=1;
    
    queue<pair<int, int>> q;
    q.push({x,y});
    
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<2;i++) {
            dx=x+(dir[i][0]*arr[x][y]);
            dy=y+(dir[i][1]*arr[x][y]);
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(visited[dx][dy]==0) {
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
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }
    
    BFS_iter(0, 0);
    if(visited[N-1][N-1]) {
        cout << "HaruHaru" << "\n";
    }
    else {
        cout << "Hing" << "\n";
    }
    
    return 0;
}

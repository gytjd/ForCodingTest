#include <iostream>
#include <queue>
using namespace std;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[504][504];
int visited[504][504];

int max_N=-987654321;

int N,M;

int BFS_iter(int x,int y) {
    int dx,dy;
    
    int count_T=0;
    visited[x][y]=1;
    queue<pair<int, int>> q;
    q.push({x,y});
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        count_T+=1;
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(arr[dx][dy]==1 and visited[dx][dy]==0) {
                visited[dx][dy]=1;
                q.push({dx,dy});
            }
        }
    }
    return count_T;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }
    
    int temp_Cnt=0;
    int temp;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(visited[i][j]==0 and arr[i][j]==1) {
                temp_Cnt+=1;
                temp=BFS_iter(i, j);
                
                if(temp>max_N) {
                    max_N=temp;
                }
            }
        }
    }
    
    cout << temp_Cnt << "\n";
    
    if(max_N==-987654321) {
        cout << 0 << "\n";
    }
    else {
        cout << max_N << "\n";
    }
    
}

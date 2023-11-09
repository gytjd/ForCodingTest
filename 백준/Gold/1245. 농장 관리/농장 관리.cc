#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool check_Flag;
int N,M;
int arr[104][74];
int visited[104][74];
int dir[8][2]={{0,1},{1,0},{0,-1},{-1,0},{-1,1},{1,1},{1,-1},{-1,-1}};

void BFS_iter(int x,int y) {
    
    int tempX,tempY;
    int dx,dy;
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()) {
        tempX=q.front().first;
        tempY=q.front().second;
        q.pop();
        
        for(int i=0;i<8;i++) {
            dx=tempX+dir[i][0];
            dy=tempY+dir[i][1];
        
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(arr[x][y]<arr[dx][dy]) {
                check_Flag=false;
            }

            if(visited[dx][dy] or arr[x][y]!=arr[dx][dy]) {
                continue;
            }
            
            visited[dx][dy]=1;
            q.push({dx,dy});
        }
    }
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
    
    int ret=0;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(visited[i][j]==0) {
                check_Flag=true;
                BFS_iter(i, j);
                
                if(check_Flag){
                    ret+=1;
                }
            }
        }
    }
    
    
    cout << ret << "\n";
    
    return 0;
}

#include <iostream>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

int test_case;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[104][104];
int visited[104][104];
int startX,startY,endX,endY;

void init_() {
    
    memset(arr,0,sizeof(arr));
    memset(visited,0,sizeof(visited));
}

void BFS_iter(int x,int y) {
    
    int dx,dy;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=100 or dy<0 or dy>=100 or visited[dx][dy]) {
                continue;
            }
            
            if(arr[dx][dy]==0 or arr[dx][dy]==3) {
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
    
    for(int test=1;test<=10;test++) {
        
        cin >> test_case;
        init_();
        
        for(int i=0;i<100;i++) {
            string data;
            cin >> data;
            
            for(int j=0;j<100;j++) {
                arr[i][j]=data[j]-'0';
                
                if(arr[i][j]==2) {
                    startX=i;
                    startY=j;
                } else if(arr[i][j]==3) {
                    endX=i;
                    endY=j;
                }
            }
        }
        
        BFS_iter(startX, startY);
        cout << "#" << test << " " << visited[endX][endY] << "\n";
        
    }
    
    return 0;
}

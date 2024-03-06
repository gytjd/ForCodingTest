#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int check,curr,x,y; // 0은 낮 1은 밤으로하자...
};

int N,M,K;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[1004][1004];
int visited[2][14][1004][1004];

void display_() {
    for(int i=0;i<2;i++) {
        for(int j=0;j<=K;j++) {
            
            cout << i << " " << j << "\n";
            for(int k=0;k<N;k++) {
                for(int q=0;q<M;q++) {
                    cout << visited[i][j][k][q] << " ";
                }
                cout << "\n";
            }
            
        }
        cout << "\n";
    }
    cout << "\n";
}
void BFS_iter(int check,int curr,int x,int y) {
    int dx,dy;
    queue<Node> q;
    q.push({check,curr,x,y});
    visited[check][curr][x][y]=1;
    
    while(!q.empty()) {
        check=q.front().check;
        curr=q.front().curr;
        x=q.front().x;
        y=q.front().y;
        
        int check_Temp=(check==1?0:1); // 다음 시간
        q.pop();
        
        if(visited[check_Temp][curr][x][y]==0) {
            visited[check_Temp][curr][x][y]=visited[check][curr][x][y]+1;
            q.push({check_Temp,curr,x,y});
        }
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(check==0) { // 현재 낮
                if(visited[check_Temp][curr][dx][dy]==0 and arr[dx][dy]==0) {
                    visited[check_Temp][curr][dx][dy]=visited[check][curr][x][y]+1;
                    q.push({check_Temp,curr,dx,dy});
                }
                
                if(curr+1<=K and visited[check_Temp][curr+1][dx][dy]==0 and arr[dx][dy]==1) {
                    visited[check_Temp][curr+1][dx][dy]=visited[check][curr][x][y]+1;
                    q.push({check_Temp,curr+1,dx,dy});
                }
            }
            else { // 밤
                if(visited[check_Temp][curr][dx][dy]==0 and arr[dx][dy]==0) {
                    visited[check_Temp][curr][dx][dy]=visited[check][curr][x][y]+1;
                    q.push({check_Temp,curr,dx,dy});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        for(int j=0;j<M;j++) {
            arr[i][j]=a[j]-'0';
        }
    }
    
    BFS_iter(0, 0, 0, 0);
    
    int answer=987654321;
    for(int i=0;i<2;i++) {
        for(int j=0;j<=K;j++) {
            if(visited[i][j][N-1][M-1]==0) continue;
            answer=min(answer,visited[i][j][N-1][M-1]);
        }
    }
    
    cout << (answer==987654321?-1:answer) << "\n";
    
    
    return 0;
}

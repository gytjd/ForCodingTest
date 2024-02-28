#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int x,y,curr_Cnt;
    int answer;
};

int K;
int N,M;
int dir_M[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dir_H[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int arr[204][204];
int visited[204][204][204];

void display_() {
    
    cout << "\n";
    
    for(int q=0;q<=K;q++) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                cout << visited[i][j][q] << " ";
            }
            cout << "\n";
        }
    }
}

int BFS_iter(int x,int y,int curr_Cnt,int answer) {
    
    int dx,dy;
    queue<Node> q;
    q.push({x,y,curr_Cnt,0});
    visited[x][y][curr_Cnt]=1;
    
    while(!q.empty()) {
        x=q.front().x;
        y=q.front().y;
        curr_Cnt=q.front().curr_Cnt;
        answer=q.front().answer;
        q.pop();
        
        if(x==N-1 and y==M-1) {
            return answer;
        }
        
        for(int i=0;i<4;i++) {
            dx=x+dir_M[i][0];
            dy=y+dir_M[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M or arr[dx][dy]==1) {
                continue;
            }
            
            if(visited[dx][dy][curr_Cnt]==0) {
                visited[dx][dy][curr_Cnt]=visited[x][y][curr_Cnt]+1;
                q.push({dx,dy,curr_Cnt,answer+1});
            }
        }
        
        if(curr_Cnt<K) {
            for(int i=0;i<8;i++) {
                dx=x+dir_H[i][0];
                dy=y+dir_H[i][1];
                
                if(dx<0 or dx>=N or dy<0 or dy>=M or arr[dx][dy]==1) {
                    continue;
                }
                
                if(visited[dx][dy][curr_Cnt+1]==0) {
                    visited[dx][dy][curr_Cnt+1]=visited[x][y][curr_Cnt]+1;
                    q.push({dx,dy,curr_Cnt+1,answer+1});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> K;
    cin >> M >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << BFS_iter(0, 0, 0,0) << "\n";
//    display_();
    
    return 0;
}

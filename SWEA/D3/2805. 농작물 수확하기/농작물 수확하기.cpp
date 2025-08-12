#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int ret;
int T,N;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[54][54];
int visited[54][54];

queue<pair<int,int>> q;
queue<pair<int,int>> temp;

void init_() {
    
    while(!q.empty()) {
        q.pop();
    }
    
    while(!temp.empty()) {
        temp.pop();
    }
    
    ret=0;
    memset(visited, 0, sizeof(visited));
}

void BFS_iter(int x,int y) {
    
    int dx,dy;
    q.push({x,y});
    visited[x][y]=1;
    ret+=arr[x][y];
    
    for(int j=0;j<N/2;j++) {
        
        while(!q.empty()) {
            x=q.front().first;
            y=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++) {
                dx=x+dir[i][0];
                dy=y+dir[i][1];
                
                if(dx<0 or dx>=N or dy<0 or dy>=N) {
                    continue;
                }
                
                if(visited[dx][dy]==0) {
                    visited[dx][dy]=1;
                    temp.push({dx,dy});
                    ret+=arr[dx][dy];
                }
            }
        }
        q=temp;
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int test=1;test<=T;test++) {
        
        init_();
        cin >> N;
        for(int i=0;i<N;i++) {
            
            string data;
            cin >> data;
            for(int j=0;j<N;j++) {
                arr[i][j]=data[j]-'0';
            }
        }
        BFS_iter(N/2, N/2);
        cout << "#" << test << " " << ret << "\n";
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T;
int ret;
int N,M,R,C,L;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool arr[54][54][54][54];
int visited[54][54];
queue<pair<int,int>> q;

void display_() {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void init_() {
    
    ret=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            visited[i][j]=0;
            for(int k=0;k<N;k++) {
                for(int u=0;u<M;u++) {
                    arr[i][j][k][u]=false;
                }
            }
        }
    }
    while(!q.empty()) {
        q.pop();
    }
}


void connect_(int x,int y,vector<int> temp) {
    
    int dx,dy;
    for(int i=0;i<4;i++) {
        for(int j=0;j<temp.size();j++) {
            if(i==temp[j]) {
                
                dx=x+dir[i][0];
                dy=y+dir[i][1];
                if(dx<0 or dx>=N or dy<0 or dy>=M) {
                    continue;
                }
                arr[x][y][dx][dy]=true;
            }
        }
    }
}

void BFS_iter() {
    
    int x,y;
    int dx,dy;
    queue<pair<int,int>> p;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        ret+=1;
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(visited[dx][dy]) continue;
            if(arr[x][y][dx][dy] and arr[dx][dy][x][y]) {
                visited[dx][dy]=1;
                p.push({dx,dy});
            }
        }
    }
    q=p;
}

void go_(int x,int y) {

    q.push({x,y});
    visited[x][y]=1;
    
    for(int i=0;i<L;i++) {
        BFS_iter();
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int test_case=1;test_case<=T;test_case++) {
        
        cin >> N >> M >> R >> C >> L;
        
        init_();
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                
                int data;
                cin >> data;
                
                if(data==1) {
                    connect_(i, j, {0,1,2,3});
                } else if(data==2) {
                    connect_(i, j, {1,3});
                } else if(data==3) {
                    connect_(i, j, {0,2});
                } else if(data==4) {
                    connect_(i, j, {0,3});
                } else if(data==5) {
                    connect_(i, j, {0,1});
                } else if(data==6) {
                    connect_(i, j, {1,2});
                } else if(data==7) {
                    connect_(i, j, {2,3});
                }
            }
            
        }
        
        go_(R, C);
        cout << "#" << test_case << " " << ret << "\n";
    }
    
    return 0;
}
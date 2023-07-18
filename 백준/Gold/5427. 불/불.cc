#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int ret=987654321;
int T,N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char arr[1004][1004];
int visited[1004][1004];
queue<pair<int, int>> p;
queue<pair<int, int>> fire;


void display_() {
    
    cout << "\n";
    for(int i=0;i<=N+1;i++) {
        for(int j=0;j<=M+1;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}
void init_() {
    for(int i=0;i<=N+1;i++) {
        for(int j=0;j<=M+1;j++) {
            arr[i][j]='.';
        }
    }
    
    while(!p.empty()) {
        p.pop();
    }
    
    while(!fire.empty()) {
        fire.pop();
    }
}

void BFS_fire() {
    
    int x,y;
    int dx,dy;
    queue<pair<int, int>> temp;
    
    while(!fire.empty()) {
        x=fire.front().first;
        y=fire.front().second;
        fire.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<=0 or dx>N or dy<=0 or dy>M or arr[dx][dy]=='#' or arr[dx][dy]=='*') {
                continue;
            }
            
            if(arr[dx][dy]=='.' or arr[dx][dy]=='@') {
                arr[dx][dy]='*';
                temp.push({dx,dy});
            }
        }
    }
    
    fire=temp;
}

void BFS_iter() {

    int x,y;
    int dx,dy;
    queue<pair<int, int>> temp;
    
    while(!p.empty()) {
        x=p.front().first;
        y=p.front().second;
        p.pop();
        
        if(x<=0 or x>N or y<=0 or y>M) {
            ret=min(ret,visited[x][y]);
        }
        
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            
            if(dx<0 or dx>N+1 or dy<0 or dy>M+1 or arr[dx][dy]=='#' or arr[dx][dy]=='*') {
                continue;
            }
            
            if(visited[dx][dy]==0 and arr[dx][dy]=='.') {
                visited[dx][dy]=visited[x][y]+1;
                temp.push({dx,dy});
            }
        }
    }
    
    p=temp;
}

void go_() {
    while(1) {
        BFS_fire();
        BFS_iter();
//        display_();
        
        if(p.size()==0) {
            break;
        }
    }
    
    if(ret==987654321) {
        cout << "IMPOSSIBLE" << "\n";
    }
    else {
        cout << ret-1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    
    for(int q=0;q<T;q++) {
        
        cin >> M >> N;
        init_();
        ret=987654321;
        memset(visited, 0, sizeof(visited));
        
        for(int i=1;i<=N;i++) {
            string a;
            cin >> a;
            for(int j=0;j<M;j++) {
                arr[i][j+1]=a[j];
                
                if(arr[i][j+1]=='*') {
                    fire.push({i,j+1});
                }
                
                if(arr[i][j+1]=='@') {
                    p.push({i,j+1});
                    visited[i][j+1]=1;
                }
            }
        }
        
        go_();
    }
}

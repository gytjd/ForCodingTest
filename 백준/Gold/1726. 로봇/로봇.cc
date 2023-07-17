#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int e,x,y,d;
};

struct cmp {
    bool operator() (Node &a,Node &b) {
        return a.e>b.e;
    }
};

int ret=987654321;
int dir[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
int N,M;
int arr[104][104];
int visited[104][104];

Node startA;
Node endA;

void display_() {
    
    cout << "\n";
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

void BFS_iter(int x,int y,int d) {
    int dx,dy;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({1,x,y,d});
    visited[x][y]=1;
    
    while(!q.empty()) {
        x=q.top().x;
        y=q.top().y;
        d=q.top().d;
        q.pop();
    
        
        for(int i=1;i<5;i++) {
            
            for(int j=1;j<=3;j++) {
                dx=x+(dir[i][0]*j);
                dy=y+(dir[i][1]*j);
                
                if(arr[dx][dy]==1) {
                    break;
                }
                
                if(dx<=0 or dx>N or dy<=0 or dy>M) {
                    continue;
                }
                
                if(((dx==endA.x and dy==endA.y) or visited[dx][dy]==0)) {
                    
                    if((d==1 and i==2) or (d==2 and i==1) or (d==3 and i==4) or (d==4 and i==3)) {
                        visited[dx][dy]=visited[x][y]+3;
                    }
                    else if(i==d) {
                        visited[dx][dy]=visited[x][y]+1;
                    }
                    else if(i!=d) {
                        visited[dx][dy]=visited[x][y]+2;
                    }
                    
                    
                    q.push({visited[dx][dy],dx,dy,i});
                    
                    
                    if(dx==endA.x and dy==endA.y) {
//                        cout << visited[dx][dy] << "\n";
                        
                        if(endA.d==i) {
                            ret=min(ret,visited[dx][dy]-1);
//                            cout << visited[dx][dy]-1 << "\n";
                        }
                        else {
                            if((i==1 and endA.d==2) or (i==2 and endA.d==1) or (i==3 and endA.d==4) or (i==4 and endA.d==3)) {
                                ret=min(ret,visited[dx][dy]+1);
//                                cout << visited[dx][dy]+1 << "\n";
                            }
                            else {
                                ret=min(ret,visited[dx][dy]);
//                                cout << visited[dx][dy] << "\n";
                            }
                        }
                    }
                }
            }
            
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin >> arr[i][j];
        }
    }
    
    cin >> startA.x >> startA.y >> startA.d;
    cin >> endA.x >> endA.y >> endA.d;
    
    if(startA.x==endA.x and startA.y==endA.y) {
        if(startA.d==endA.d) {
            cout << 0 << "\n";
        }
        else {
            if((startA.d==1 and endA.d==2) or (startA.d==2 and endA.d==1) or (startA.d==3 and endA.d==4) or (startA.d==4 and endA.d==3)) {
                cout << 2 << "\n";
            }
            else {
                cout << 1 << "\n";
            }
        }
    }
    else {
        BFS_iter(startA.x, startA.y, startA.d);
        cout << ret << "\n";
    }
    return 0;
}

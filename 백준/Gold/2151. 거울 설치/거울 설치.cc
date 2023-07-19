#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int e,x,y,d;
};

struct cmp {
    bool operator()(Node &a,Node &b) {
        return a.e>b.e;
    }
};

int ret=987654321;
int N;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char arr[54][54];
int visited[54][54][4];
vector<pair<int, int>> dst;
priority_queue<Node,vector<Node>,cmp> q;

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<4;k++) {
                cout << visited[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

void BFS_iter() {
    int x,y,d;
    int dx,dy;
    
    while(!q.empty()) {
        x=q.top().x;
        y=q.top().y;
        d=q.top().d;
        q.pop();
        
        if(x==dst[1].first and y==dst[1].second) {
            ret=min(ret,visited[x][y][d]-1);
            continue;
        }
        
        if(arr[x][y]=='.') {
            dx=x+dir[d][0];
            dy=y+dir[d][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N or arr[dx][dy]=='*') {
                continue;
            }
            
            if(visited[dx][dy][d]==0) {
                visited[dx][dy][d]=visited[x][y][d];
                q.push({visited[dx][dy][d],dx,dy,d});
            }
        }
        else if(arr[x][y]=='!') {
            
            for(int i=0;i<4;i++) {
                dx=x+dir[i][0];
                dy=y+dir[i][1];
                
                if(dx<0 or dx>=N or dy<0 or dy>=N or arr[dx][dy]=='*') {
                    continue;
                }
                
                if(visited[dx][dy][i]==0) {
                    if(i==d) {
                        visited[dx][dy][i]=visited[x][y][d];
                    }
                    else {
                        visited[dx][dy][i]=visited[x][y][d]+1;
                    }
                    q.push({visited[dx][dy][i],dx,dy,i});
                }
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
        string a;
        cin >> a;
        for(int j=0;j<N;j++) {
            arr[i][j]=a[j];
            
            if(arr[i][j]=='#') {
                dst.push_back({i,j});
            }
        }
    }
    
    int dx,dy;
//    visited[dst[0].first][dst[0].second]=1;
    for(int i=0;i<4;i++) {
        dx=dst[0].first+dir[i][0];
        dy=dst[0].second+dir[i][1];
        
        if(dx<0 or dy>=N or dy<0 or dy>=N or arr[dx][dy]=='*') {
            continue;
        }
        
        visited[dx][dy][i]=1;
        q.push({visited[dx][dy][i],dx,dy,i});
    }
    
    BFS_iter();
    
    cout << ret << "\n";
    
    return 0;
}


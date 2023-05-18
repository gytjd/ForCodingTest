#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int a,b,c,d;
int visited[1004][1004];
int dir[3][2]={{a,0},{0,b},{0,0}};

int go_(queue<pair<int,int>> &q,int x,int y,int n) {
    
    int dx,dy;
    if(n==0) {
        dx=a;
        dy=y;
    }
    else if(n==1) {
        dx=x;
        dy=b;
    }
    else if(n==2) {
        dx=0;
        dy=y;
    }
    else if(n==3) {
        dx=x;
        dy=0;
    }
    else if(n==4) {
        if(x<=b-y) {
            dx=0;
            dy=y+x;
        }
        else {
            dx=(x+y)-b;
            dy=b;
        }
    }
    else if(n==5) {
        if(y<=a-x) {
            dx=x+y;
            dy=0;
        }
        else {
            dy=(x+y)-a;
            dx=a;
            
        }
    
    }
    
    if(visited[dx][dy]==0) {
        visited[dx][dy]=visited[x][y]+1;
        q.push({dx,dy});
    }
    
    if(dx==c and dy==d) {
        return 1;
    }
    
    return 0;
}
void BFS_iter(int x,int y) {
    
    bool check_Flag=false;
    visited[x][y]=1;
    queue<pair<int, int>> q;
    q.push({x,y});
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<6;i++) {
            if(go_(q, x, y, i)) {
                check_Flag=true;
                break;
            }
        }
        
        if(check_Flag) {
            break;
        }
    }
    
    if(check_Flag) {
        cout << visited[x][y] << "\n";
    }
    else {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> a >> b >> c >> d;
    
    if(c==0 and d==0) {
        cout << 0 << "\n";
    }
    else {
        BFS_iter(0, 0);
    }
    
    return 0;
}


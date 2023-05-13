#include <iostream>
#include <queue>
using namespace std;

int temp[304][304];
int dir[8][2]={{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};

int size_n;
int startX,startY;
int endX,endY;

void init_(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            temp[i][j]=0;
        }
    }
}

void BFS_iter(int x,int y) {
    
    int dx,dy;
    temp[x][y]=0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        if(x==endX and y==endY) {
            cout << temp[x][y] << "\n";
            break;
        }
        
        for(int i=0;i<8;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=size_n or dy<0 or dy>=size_n) {
                continue;
            }
            
            if(temp[dx][dy]==0) {
                q.push(make_pair(dx, dy));
                temp[dx][dy]=temp[x][y]+1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++) {
        cin >> size_n;

        init_(size_n);
        cin >> startX >> startY;
        cin >> endX >> endY;
        
        BFS_iter(startX, startY);
    }
    
    return 0;
}

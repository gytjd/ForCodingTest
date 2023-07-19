#include <iostream>
#include <queue>
using namespace std;

int ret;
int dir[9][2]={{0,0},{0,1},{1,0},{0,-1},{-1,0},{-1,1},{1,1},{1,-1},{-1,-1}};
char arr[8][8];
int visited[8][8];
queue<pair<int, int>> q;

void display_() {
    
    cout << "\n";
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
void down_() {
    for(int i=7;i>=1;i--) {
        for(int j=0;j<8;j++) {
            arr[i][j]=arr[i-1][j];
        }
    }
    for(int i=0;i<8;i++) {
        arr[0][i]='.';
    }
}

void BFS_iter() {
    
    int x,y;
    int dx,dy;
    queue<pair<int, int>> temp;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        if(x==0 and y==7) {
            ret=1;
        }
        
        if(arr[x][y]=='#') {
            continue;
        }
        
        for(int i=0;i<9;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=8 or dy<0 or dy>=8 or arr[dx][dy]=='#') {
                continue;
            }
            
            if(arr[dx][dy]=='.') {
                temp.push({dx,dy});
            }
        }
    }
    q=temp;
    
}
void go_() {
    
    for(int i=0;i<8;i++) {
        BFS_iter();
        down_();
    }
    
    if(q.empty()) {
        cout << 0 << "\n";
    }
    else {
        cout << 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i=0;i<8;i++) {
        string a;
        cin >> a;
        for(int j=0;j<8;j++) {
            arr[i][j]=a[j];
        }
    }
    q.push({7,0});
    visited[7][0]=1;
    go_();
    
    return 0;
}

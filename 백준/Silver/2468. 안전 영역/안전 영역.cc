#include <iostream>
#include <queue>
using namespace std;

int arr[104][104];
int temp[104][104];
int visited[104][104];


int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int N;

int max_N=-987654321;
int min_N=987654321;

void init_(int tmp) {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(arr[i][j]<=tmp) {
                temp[i][j]=1;
            }
            else {
                temp[i][j]=0;
            }
            
            visited[i][j]=0;
        }
    }
}

void BFS_iter(int x,int y) {
    
    int dx,dy;
    visited[x][y]=1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
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
            
            if(temp[dx][dy]==0 and visited[dx][dy]==0) {
                visited[dx][dy]=1;
                q.push(make_pair(dx, dy));
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
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
            
            if(max_N<arr[i][j]) {
                max_N=arr[i][j];
            }
            
            if(min_N>arr[i][j]) {
                min_N=arr[i][j];
            }
        }
    }
    
    int tot=1;
    for(int q=min_N;q<=max_N;q++) {
        init_(q);
        
        int Cnt=0;
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(temp[i][j]==0 and visited[i][j]==0) {
                    Cnt+=1;
                    BFS_iter(i, j);
                }
            }
        }
        
        if(Cnt>tot) {
            tot=Cnt;
        }
    }
    
    cout << tot << "\n";
    
    return 0;
}

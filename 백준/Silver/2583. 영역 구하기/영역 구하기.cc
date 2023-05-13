#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[104][104];
int visited[104][104];

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int N,M,K;
vector<int> ret;

void init_(int x1,int y1,int x2,int y2) {
    
    for(int i=y1;i<y2;i++) {
        for(int j=x1;j<x2;j++) {
            arr[i][j]=1;
        }
    }
}

void BFS_iter(int x,int y) {
    
    int cnt_T=0;
    int dx,dy;
    visited[x][y]=1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        cnt_T+=1;
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(arr[dx][dy]==0 and visited[dx][dy]==0) {
                visited[dx][dy]=1;
                q.push(make_pair(dx, dy));
            }
        }
    }
    
    ret.push_back(cnt_T);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> K;
    
    for(int i=0;i<K;i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        init_(x1,y1,x2,y2);
    }
    
    int tot=0;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr[i][j]==0 and visited[i][j]==0) {
                tot+=1;
                BFS_iter(i, j);
            }
        }
    }
    
    sort(ret.begin(), ret.end());
    
    cout << tot << "\n";
    for(int a:ret) {
        cout << a << " ";
    }
    cout << "\n";
    
    return 0;
}

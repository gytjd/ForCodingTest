#include <iostream>
#include <queue>

using namespace std;

int arr[1004][1004];
int visited[1004][1004];
int N,M;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

void BFS_iter(int x,int y){
    
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
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(arr[dx][dy]==0 and visited[dx][dy]==0) {
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
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        
        for(int j=0;j<M;j++) {
            arr[i][j]=a[j]-'0';
        }
    }
    
    for(int i=0;i<M;i++) {
        if(arr[0][i]==0 and visited[0][i]==0) {
            BFS_iter(0, i);
        }
    }
    
    bool check_Flag=false;
    for(int i=0;i<M;i++) {
        if(visited[N-1][i]==1) {
            check_Flag=true;
            break;
        }
    }
    
    if(check_Flag==true) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
    
    return 0;
}

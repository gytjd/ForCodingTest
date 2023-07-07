#include <iostream>
#include <queue>

using namespace std;


int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[3004][3004];
int visited[3004][3004];
queue<pair<int, int>> q;

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
            
            if(arr[i][j]==2) {
                q.push({i,j});
                visited[i][j]=1;
            }
        }
    }
    
    int x,y;
    int dx,dy;

    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M or arr[dx][dy]==1) {
                continue;
            }
            
            if(visited[dx][dy]==0) {
                visited[dx][dy]=visited[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
    
    int ret=987654321;
    bool check_Flag=false;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(visited[i][j]!=0 and (arr[i][j]==3 or arr[i][j]==4 or arr[i][j]==5)) {
                ret=min(ret,visited[i][j]-1);
                check_Flag=true;
            }
        }
    }
    
    if(check_Flag) {
        cout << "TAK" << "\n";
        cout << ret << "\n";
    }
    else {
        cout << "NIE" << "\n";
    }
    
    return 0;
}

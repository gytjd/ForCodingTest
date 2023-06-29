#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[104][104];
int visited[104][104];

queue<pair<int, int>> q;

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

int is_check() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr[i][j]==1) {
                return 0;
            }
        }
    }
    
    return 1;
}
void flood_F() {
    
    int x,y;
    int dx,dy;
    
    queue<pair<int, int>> temp;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
//        cout << x << " " << y << "\n";
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            
            if(arr[dx][dy]==1) {
                visited[dx][dy]+=1;
            }
            else if(arr[dx][dy]==0 and visited[dx][dy]==0) {
                visited[dx][dy]=1;
                q.push({dx,dy});
            }
            
            if(visited[dx][dy]>=2 and arr[dx][dy]==1) {
                arr[dx][dy]=0;
                temp.push({dx,dy});
            }
        }
    }
    
    q=temp;
}

void go_() {
    
    int ret=0;
    q.push({0,0});
    visited[0][0]=1;
    
    while(!is_check()) {
        flood_F();
        ret+=1;
    }
    
    cout << ret << "\n";
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }
    
    go_();
    
    return 0;
}

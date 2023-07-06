#include <iostream>
#include <queue>
using namespace std;

int a,b,c;
int N,M,T;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[1004][1004];
int visited[1004][1004];

//void display_() {
//
//    cout << "\n";
//    for(int i=0;i<N;i++) {
//        for(int j=0;j<M;j++) {
//            cout << arr[i][j] << " ";
//        }
//        cout << "\n";
//    }
//}

void go_(int x,int y) {
    int dx,dy;
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
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
            
            if(visited[dx][dy]==0 and arr[dx][dy]==255) {
                visited[dx][dy]=1;
                q.push({dx,dy});
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
        for(int j=0;j<M;j++) {
            for(int k=0;k<3;k++) {
                int temp;
                cin >> temp;
                arr[i][j]+=temp;
            }
        }
    }
    cin >> T;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr[i][j]/3>=T) {
                arr[i][j]=255;
            }
            else {
                arr[i][j]=0;
            }
        }
    }
    
    
    int ret=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(visited[i][j]==0 and arr[i][j]==255) {
                go_(i, j);
                ret+=1;
            }
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}

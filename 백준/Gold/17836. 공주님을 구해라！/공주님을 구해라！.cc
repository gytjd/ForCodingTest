#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int startX,startY;
int N,M,T;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[104][104];
int visited[104][104];

void BFS_iter(int x,int y) {
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
            
            if(dx<0 or dx>=N or dy<0 or dy>=M or arr[dx][dy]==1) {
                continue;
            }
            
            if(visited[dx][dy]==0 and (arr[dx][dy]==0 or arr[dx][dy]==2)) {
                visited[dx][dy]=visited[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
}

void BFS_Sword(int x,int y) {
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
            
            if(visited[dx][dy]==0) {
                visited[dx][dy]=visited[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
}

void go_() {
    BFS_iter(0, 0);
    int ret=visited[N-1][M-1]-1;
    int temp=visited[startX][startY]-1;
    
    if(ret==-1) { // 도착을 못함,,,
        if(temp==-1) { // 검도 못주움,,
            cout << "Fail" << "\n";
        }
        else { // 도착은 못했는데 검은 주움 그럼 해봐야지
            memset(visited, 0, sizeof(visited));
            BFS_Sword(startX, startY);
            
            if(visited[N-1][M-1]==0) { // 검줍고도 못감 실패
                cout << "Fail" << "\n";
            }
            else { // 검줍고 뒤 상황
                temp+=(visited[N-1][M-1]-1);
                if(temp<=T) { // 이러면 답
                    cout << temp << "\n";
                }
                else { // 검줍고 도착했는데 더 큼;;
                    cout << "Fail" << "\n";
                }
            }
            
        }
    }
    else { // 도착을 함
        if(temp==-1) { // 근데 검을 못주음;.. 그럼 바로 답 ㄱㄱ
            if(ret<=T) {
                cout << ret << "\n";
            }
            else {
                cout << "Fail" << "\n";
            }
        }
        else { // 검도 줍고함 그럼 누가 더 작은지 해봐야함
            memset(visited, 0, sizeof(visited));
            BFS_Sword(startX, startY);
            
            if(visited[N-1][M-1]==0) { // 검을 잡고 도착을 못함,, 그럼 그냥 ret
                if(ret<=T) {
                    cout << ret << "\n";
                }
                else {
                    cout << "Fail" << "\n";
                }
            }
            else {
                temp+=(visited[N-1][M-1]-1);
                ret=min(ret,temp);
                
                if(ret<=T) {
                    cout << ret << "\n";
                }
                else {
                    cout << "Fail" << "\n";
                }
            }
        }
    }
    
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> T;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            if(arr[i][j]==2) {
                startX=i;
                startY=j;
            }
        }
    }
    
    go_();
    
    return 0;
}

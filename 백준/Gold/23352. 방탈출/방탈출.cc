#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[54][54];
int visited[54][54];

pair<int,int> BFS_iter(int x,int y) {
    
    int dx,dy;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    int temp_Idx=1; // 경로 길이라고 하자
    int temp_Ret=0; // 그 값
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M or arr[dx][dy]==0) {
                continue;
            }
            
            if(visited[dx][dy]==0) {
                visited[dx][dy]=visited[x][y]+1;
                
                if(visited[dx][dy]>=temp_Idx) {
                    if(temp_Idx==visited[dx][dy]) {
                        temp_Ret=max(temp_Ret,arr[dx][dy]);
                    } else {
                        temp_Ret=arr[dx][dy];
                    }
                    temp_Idx=visited[dx][dy];
                }
                q.push({dx,dy});
            }
        }
    }
    
    return {temp_Idx,temp_Ret};
}

void go_() {
    
    int ret=0;
    int retIdx=0;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            memset(visited, 0, sizeof(visited));

            if(arr[i][j]) {
                pair<int,int> temp=BFS_iter(i, j);
                if(temp.first>=retIdx) {
                    if(temp.first==retIdx) {
                        ret=max(ret,arr[i][j]+temp.second);
                    } else {
                        ret=arr[i][j]+temp.second;
                    }
                    retIdx=temp.first;
                }
            }
        }
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

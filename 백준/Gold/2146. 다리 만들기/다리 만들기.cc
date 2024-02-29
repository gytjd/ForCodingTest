#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int answer=1000;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[104][104];
int visited[104][104];
vector<pair<int,int>> start;

void display_() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
void BFS_init(int x,int y,int temp_Num) {
    int dx,dy;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=1;
    arr[x][y]=temp_Num;
    
    while(!q.empty()) {
        int temp_Cnt=0;
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(visited[dx][dy]==0 and arr[dx][dy]==1) {
                visited[dx][dy]=1;
                arr[dx][dy]=temp_Num;
                q.push({dx,dy});
            }
            
            if(arr[dx][dy]==0) {
                temp_Cnt+=1;
            }
        }
        
        if(temp_Cnt) {
            start.push_back({x,y});
        }
        
    }
}

void init_() {
    
    int temp_Num=1;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(visited[i][j]==0 and arr[i][j]) {
                BFS_init(i, j,temp_Num++);
            }
        }
    }
}

int BFS_iter(int x,int y,int curr) {
    int dx,dy;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        if(arr[x][y]!=curr and arr[x][y]!=0) {
            return visited[x][y]-2;
        }
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(visited[dx][dy]==0) {
                visited[dx][dy]=visited[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
    
    return -1;
}

void go_() {
    
    for(pair<int,int> temp:start) {
        memset(visited,0,sizeof(visited));
        answer=min(answer,BFS_iter(temp.first, temp.second, arr[temp.first][temp.second]));
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
        }
    }
    
    init_();
    go_();
    cout << answer << "\n";
    
    return 0;
}

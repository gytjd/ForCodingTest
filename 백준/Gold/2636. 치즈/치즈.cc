#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N,M;
int ret;
int retCnt;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[104][104];
int visited[104][104];
vector<pair<int,int>> v;

void display_() {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void BFS_iter(int x,int y) {
    
    int dx,dy;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M or visited[dx][dy]) {
                continue;
            }
            
            visited[dx][dy]=1;
            if(arr[dx][dy]) v.push_back({dx,dy});
            else q.push({dx,dy});
        }
    }
}

void go_() {
    
    while(true) {
        
        v.clear();
        memset(visited,0,sizeof(visited));
        BFS_iter(0, 0);
        if(v.empty()) break;
        
        for(pair<int,int> temp:v) {
            arr[temp.first][temp.second]=0;
        }
        ret+=1;
        retCnt=v.size();
    }
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
    cout << ret << "\n";
    cout << retCnt << "\n";
    
    return 0;
}

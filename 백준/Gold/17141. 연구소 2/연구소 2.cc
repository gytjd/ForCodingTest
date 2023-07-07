#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int ret=987654321;
int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[54][54];
int visited[54][54];

vector<pair<int, int>> vir;
int vir_visited[14];

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

int is_check() {
    
    int count_T=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(visited[i][j]==0 and (arr[i][j]==0 or arr[i][j]==2)) {
                return 987654321;
            }
            count_T=max(count_T,visited[i][j]-1);
        }
    }
    
    return count_T;
}

void BFS_iter(queue<pair<int, int>> &q) {
    
    int x,y;
    int dx,dy;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N or arr[dx][dy]==1) {
                continue;
            }
            
            if(visited[dx][dy]==0) {
                visited[dx][dy]=visited[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
}

void go_(int start,int depth) {
    
    if(depth==M) {
        queue<pair<int, int>> q;
        memset(visited, 0, sizeof(visited));
        
        for(int i=0;i<vir.size();i++) {
            if(vir_visited[i]==1) {
                visited[vir[i].first][vir[i].second]=1;
                q.push({vir[i].first,vir[i].second});
            }
        }
        
        BFS_iter(q);
        ret=min(ret,is_check());
        return;
    }
    
    for(int i=start;i<vir.size();i++) {
        if(vir_visited[i]==0) {
            vir_visited[i]=1;
            go_(i+1, depth+1);
            vir_visited[i]=0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
            if(arr[i][j]==2) {
                vir.push_back({i,j});
            }
        }
    }
    
    go_(0, 0);
    if(ret==987654321) {
        cout << -1 << "\n";
    }
    else {
        cout << ret << "\n";
    }
    
    return 0;
}

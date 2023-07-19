#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[1004][1004];
int visited[1004][1004];

int cnt_T;
vector<int> tot;

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}
int BFS_iter(int x,int y,int d) {
    int ret=0;
    int dx,dy;
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y]=d;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        ret+=1;
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M or arr[dx][dy]==0) {
                continue;
            }
            
            if(visited[dx][dy]==-1) {
                visited[dx][dy]=d;
                q.push({dx,dy});
            }
        }
    }
    return ret;
}

void find_Max() {
    
    int ret=0;
    int dx,dy;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            int temp=0;
            if(arr[i][j]==0) {
                
                map<int, bool> m;
                for(int k=0;k<4;k++) {
                    dx=i+dir[k][0];
                    dy=j+dir[k][1];
                    
                    if(dx<0 or dx>=N or dy<0 or dy>=M or arr[dx][dy]==0) {
                        continue;
                    }
                    
                    if(visited[dx][dy]!=-1 and m[visited[dx][dy]]==0) {
                        temp+=tot[visited[dx][dy]];
                        m[visited[dx][dy]]=1;
                    }
                    
                }
                
            }
            
            ret=max(ret,temp+1);
        }
    }
    
    cout << ret << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(visited, -1, sizeof(visited));
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(visited[i][j]==-1 and arr[i][j]==1) {
                tot.push_back(BFS_iter(i, j, cnt_T));
                cnt_T+=1;
            }
        }
    }
    
    find_Max();
    
    return 0;
}

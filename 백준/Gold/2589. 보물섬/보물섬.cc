#include <iostream>
#include <queue>

using namespace std;

char temp[50][50];
int visited[50][50];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int N,M;

void init_() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            visited[i][j]=0;
        }
    }
}

int BFS_iter(int x,int y) {
    
    int count=1;
    int dx,dy;
    visited[x][y]=1;
    queue<pair<int, int>>q;
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
            
            if(temp[dx][dy]=='L' and visited[dx][dy]==0) {
                visited[dx][dy]=visited[x][y]+1;
                if(count<visited[dx][dy]) {
                    count=visited[dx][dy];
                }
                q.push(make_pair(dx, dy));
            }
        }
    }
    
    return count;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        
        for(int j=0;j<a.size();j++) {
            temp[i][j]=a[j];
        }
    }
    
    int tot_cnt=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(temp[i][j]=='L') {
                
                init_();
                int check_count=BFS_iter(i, j)-1;
                
                if(tot_cnt==0) {
                    tot_cnt=check_count;
                }
                else {
                    if(tot_cnt<check_count) {
                        tot_cnt=check_count;
                    }
                }
            }
        }
    }
    
    cout << tot_cnt << "\n";
    return 0;
}

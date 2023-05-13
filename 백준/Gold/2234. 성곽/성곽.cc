#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[54][54];
int visited[54][54];

int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

int M,N;

vector<int> tot;

int BFS_iter(int x,int y,int data) {
    
    int tmp_Cnt=0;
    visited[x][y]=data;
    
    int dx,dy;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
//        cout << x << " " << y << "\n";
        
        tmp_Cnt+=1;
        
        for(int i=0;i<4;i++) {
            
            if((arr[x][y]&(1<<i))==0) {
                dx=x+dir[i][0];
                dy=y+dir[i][1];
                
                if(visited[dx][dy]==0) {
                    visited[dx][dy]=data;
                    q.push(make_pair(dx, dy));
                }
            }
        }
    }
    
    return tmp_Cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> M >> N;
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin >> arr[i][j];
        }
    }
    
    int max_ret=-987654321;
    int ret_Cnt=1;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(visited[i][j]==0) {
                int tmp=BFS_iter(i, j,ret_Cnt);
                tot.push_back(tmp);
                if(tmp>max_ret) {
                    max_ret=tmp;
                }
                ret_Cnt+=1;
            }
        }
    }
    
    int tot_Cnt=-987654321;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            
            int tx,ty;
            for(int k=0;k<4;k++) {
                tx=i+dir[k][0];
                ty=j+dir[k][1];
                
                if(tx<1 or tx>N or ty<1 or ty>M) {
                    continue;
                }
                
                int tempA=visited[i][j];
                int tempB=visited[tx][ty];
                
                if(tempA!=tempB) {
                    
                    int tmp_r=tot[tempA-1]+tot[tempB-1];
                    if(tot_Cnt<tmp_r) {
                        tot_Cnt=tmp_r;
                    }
                }
            }
        }
    }
    
    cout << ret_Cnt-1 << "\n";
    cout << max_ret << "\n";
    cout << tot_Cnt << "\n";
    
    return 0;
    
}

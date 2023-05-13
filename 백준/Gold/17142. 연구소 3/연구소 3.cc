#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int arr[54][54];
int visited[54][54];

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

queue<pair<int,int>> q;
vector<pair<int, int>> virus;
int virus_check[14];
int tot_min=987654321;

void init_() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            visited[i][j]=0;
        }
    }
}


void BFS_iter(){

    int x,y;
    int dx,dy;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(visited[dx][dy]==0 and (arr[dx][dy]==0 or arr[dx][dy]==2)) {
                
                visited[dx][dy]=visited[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
}

void DFS_recur(int start,int depth) {
    
    if(depth==M) {
        init_();
        
        for(int i=0;i<14;i++) {
            if(virus_check[i]==1) {
                q.push(virus[i]);
                visited[virus[i].first][virus[i].second]=1;
            }
        }
        
        BFS_iter();
        
        int temp_max=-987654321;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(arr[i][j]==0 and visited[i][j]!=0) {
                    
                    if(temp_max<visited[i][j]) {
                        temp_max=visited[i][j];
                    }
                }
            }
        }
        
    
        if(temp_max==-987654321) {
            temp_max=0;
        }
        
        
        bool check_Flag=false;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(arr[i][j]==0 and visited[i][j]==0) {
                    check_Flag=true;
                    break;
                }
            }
            
            if(check_Flag) {
                break;
            }
        }
        
        
        if(!check_Flag) {
            if(tot_min>temp_max) {
                tot_min=temp_max;
            }
        }
        
        
        
        return;
    }
    
    for(int i=start;i<virus.size();i++) {
        virus_check[i]=1;
        DFS_recur(i+1, depth+1);
        virus_check[i]=0;
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
                virus.push_back({i,j});
            }
        }
    }
    
    DFS_recur(0, 0);
    
    if(tot_min==987654321) {
        cout << -1 << "\n";
    }
    else {
        if(tot_min==0) {
            cout << 0 << "\n";
        }
        else {
            cout << tot_min-1 << "\n";
        }
    }
    
    return 0;
}

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[304][304];
int visited[304][304];
queue<pair<int, int>> q;

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void is_check(int x,int y) {
    

    int dx,dy;
    queue<pair<int, int>> t;
    t.push({x,y});
    visited[x][y]=1;
    
    while(!t.empty()) {
        x=t.front().first;
        y=t.front().second;
        t.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 and dx>=N and dy<0 and dy>=M) {
                continue;
            }
            
            if(arr[dx][dy]!=0 and visited[dx][dy]==0) {
                visited[dx][dy]=1;
                t.push({dx,dy});
            }
        }
    }
    
}

void melt_() {
    
    int ice_Cnt=0;
    int x,y;
    int dx,dy;
    int arr_Temp[304][304]={0,};
    queue<pair<int, int>> temp;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        ice_Cnt=0;
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx>=0 and dx<N and dy>=0 and dy<M and arr[dx][dy]==0) {
                ice_Cnt+=1;
            }
        }
        
        if(arr[x][y]-ice_Cnt>0) {
            arr_Temp[x][y]=arr[x][y]-ice_Cnt;
            temp.push({x,y});
        }
        else {
            arr_Temp[x][y]=0;
        }
    }
    
    q=temp;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            arr[i][j]=arr_Temp[i][j];
        }
    }
}

void go_() {
    
    int count_T=0;
    
    while(1) {
        
        int temp_C=0;
        memset(visited, 0, sizeof(visited));
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(visited[i][j]==0 and arr[i][j]!=0) {
                    is_check(i,j);
                    temp_C+=1;
                }
            }
        }
        
        if(temp_C==0) {
            cout << 0 << "\n";
            break;
        }
        
        if(temp_C>=2) {
            cout << count_T << "\n";
            break;
        }
        
        melt_();
        count_T+=1;
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
            if(arr[i][j]!=0) {
                q.push({i,j});
            }
        }
    }
    
    go_();
    
    return 0;
}


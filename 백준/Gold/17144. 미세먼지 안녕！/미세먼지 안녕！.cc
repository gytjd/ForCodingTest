#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[54][54];

int N,M,T;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

struct Node {
    int x;
    int y;
};

queue<Node> q;
vector<Node> air;

void init_() {
    
    while(!q.empty()) {
        q.pop();
    }
    air.clear();
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            
            if(arr[i][j]!=0 and arr[i][j]!=-1) {
                q.push({i,j});
            }
            else if(arr[i][j]==-1) {
                air.push_back({i,j});
            }
        }
    }
}

void BFS_iter() {
    
    
    int tmp_ret[54][54]={0,};
    
    int x,y;
    int dx,dy;
    
    while(!q.empty()) {
        x=q.front().x;
        y=q.front().y;
        q.pop();
        
        int cnt_T=0;
        int temp=arr[x][y]/5;
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M or arr[dx][dy]==-1) {
                continue;
            }
            
            cnt_T+=1;
            tmp_ret[dx][dy]+=temp;
        }
        
        arr[x][y]-=(temp*cnt_T);
        tmp_ret[x][y]+=arr[x][y];
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            
            if(arr[i][j]==-1) {
                continue;
            }
            arr[i][j]=tmp_ret[i][j];
        }
    }
}

void move_up() {
    Node tempA=air[0];
    int i;
    int tmpA=arr[tempA.x][M-1];
    for(i=M-1;i>tempA.y;i--) {
        
        if(i==1) {
            arr[tempA.x][i]=0;
        }
        else {
            arr[tempA.x][i]=arr[tempA.x][i-1];
        }
    }
    
    int tmpB=arr[0][M-1];
    for(int i=0;i<tempA.x;i++) {
        
        if(i==tempA.x-1) {
            arr[i][M-1]=tmpA;
        }
        else {
            arr[i][M-1]=arr[i+1][M-1];
        }
    }
    
    tmpA=arr[0][0];
    for(int i=0;i<M-1;i++) {
        if(i==M-2) {
            arr[0][i]=tmpB;
        }
        else {
            arr[0][i]=arr[0][i+1];
        }
    }
    
    for(int i=tempA.x-1;i>0;i--) {
        
        if(i==1) {
            arr[i][tempA.y]=tmpA;
        }
        else {
            arr[i][tempA.y]=arr[i-1][tempA.y];
        }
    }
}

void move_down_() {
    Node tempA=air[1];
    int i;
    int tmpA=arr[tempA.x][M-1];
    for(i=M-1;i>tempA.y;i--) {
        
        if(i==1) {
            arr[tempA.x][i]=0;
        }
        else {
            arr[tempA.x][i]=arr[tempA.x][i-1];
        }
    }
    
    int tmpB=arr[N-1][M-1];
    for(int i=N-1;i>tempA.x;i--) {
        
        if(i==tempA.x+1) {
            arr[i][M-1]=tmpA;
        }
        else {
            arr[i][M-1]=arr[i-1][M-1];
        }
    }
    
    tmpA=arr[N-1][0];
    for(int i=0;i<M-1;i++) {
        if(i==M-2) {
            arr[N-1][i]=tmpB;
        }
        else {
            arr[N-1][i]=arr[N-1][i+1];
        }
    }
    
    for(int i=tempA.x+1;i<N-1;i++) {
        
        if(i==N-2) {
            arr[i][tempA.y]=tmpA;
        }
        else {
            arr[i][tempA.y]=arr[i+1][tempA.y];
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
        }
    }
    
    for(int i=0;i<T;i++) {
        init_();
        BFS_iter();
        move_up();
        move_down_();
    }
    
    int tot=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr[i][j]==-1) {
                continue;
            }
            
            tot+=arr[i][j];
        }
    }
    
    cout << tot << "\n";
    
    return 0;
}

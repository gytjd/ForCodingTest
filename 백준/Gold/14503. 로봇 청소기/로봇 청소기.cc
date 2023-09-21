#include <iostream>
using namespace std;

struct Node {
    int x,y,d;
};

int ret;
int N,M;
int arr[54][54];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
Node curr;

int is_check(int x,int y) {
    
    int dx,dy;
    for(int i=0;i<4;i++) {
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        
        if(dx<0 or dx>=N or dy<0 or dy>=M) {
            continue;
        }
        
        if(arr[dx][dy]==0) {
            return 0; // 빈칸이 있음
        }
    }
    return 1; // 빈칸이 없는경우
}

int change_90(int d) {
    
    if(d==0) {
        return 3;
    }
    else if(d==1) {
        return 0;
    }
    else if(d==2) {
        return 1;
    }
    else {
        return 2;
    }
}


void go_() {
    
    while(true) {
        
        if(arr[curr.x][curr.y]==0) {
            arr[curr.x][curr.y]=2;
            ret+=1;
        }
        
        if(is_check(curr.x, curr.y)) { // 2A
            
            int dx,dy;
            dx=curr.x+dir[(curr.d+2)%4][0];
            dy=curr.y+dir[(curr.d+2)%4][1];
            
            if(dx>=0 and dx<N and dy>=0 and dy<M and arr[dx][dy]!=1) {
                curr.x=dx;
                curr.y=dy;
            }
            else {
                break;
            }
            
        }
        else { // 3A
            curr.d=(curr.d+3)%4;
            int dx=curr.x+dir[curr.d][0];
            int dy=curr.y+dir[curr.d][1];
            
            if(arr[dx][dy]==0 and dx>=0 and dx<N and dy>=0 and dy<M) {
                curr.x+=dir[curr.d][0];
                curr.y+=dir[curr.d][1];
            }
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    cin >> curr.x >> curr.y >> curr.d;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }
    
    go_();

    cout << ret << "\n";
    
    return 0;
}

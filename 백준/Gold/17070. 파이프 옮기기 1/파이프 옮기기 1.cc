#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[20][20];
int dir[3][2]={{0,1},{1,1},{1,0}};
int ret;

struct Node {
    int curr;
    int x,y;
};


void DFS_recur(int curr,int x,int y) {
    
    
    int dx,dy;
    
    if(x==N-1 and y==N-1) {
        ret+=1;
        return;
    }
    
    
    if(curr==0) {
        
        for(int i=0;i<2;i++) {
            bool check_Flag=false;
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(i==1) {
                for(int j=0;j<3;j++) {
                    if(arr[x+dir[j][0]][y+dir[j][1]]==1) {
                        check_Flag=true;
                        break;
                    }
                }
            }
            else {
                if(arr[dx][dy]==1) {
                    check_Flag=true;
                }
            }
            
            if(!check_Flag) {
                DFS_recur(i, dx, dy);
            }
        }
    }
    else if(curr==1) {
        
        for(int i=0;i<3;i++) {
            bool check_Flag=false;
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(i==1) {
                for(int j=0;j<3;j++) {
                    if(arr[x+dir[j][0]][y+dir[j][1]]==1) {
                        check_Flag=true;
                        break;
                    }
                }
            }
            else {
                if(arr[dx][dy]==1) {
                    check_Flag=true;
                }
            }
            
            if(!check_Flag) {
                DFS_recur(i, dx, dy);
            }
        }
    }
    else if(curr==2) {
        
        for(int i=1;i<3;i++) {
            bool check_Flag=false;
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(i==1) {
                for(int j=0;j<3;j++) {
                    if(arr[x+dir[j][0]][y+dir[j][1]]==1) {
                        check_Flag=true;
                        break;
                    }
                }
            }
            else {
                if(arr[dx][dy]==1) {
                    check_Flag=true;
                }
            }
            
            if(!check_Flag) {
                DFS_recur(i, dx, dy);
            }
        }
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
    
    DFS_recur(0, 0, 1);
    
    cout << ret << "\n";
    
    return 0;
}

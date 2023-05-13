#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N,Q;
int arr[68][68];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int temp[68][68];
int temp_ice[68][68];
int visited[68][68];

int ret;
void display_() {
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void BFS_iter(int x,int y) {
    
    int dx,dy;
    visited[x][y]=1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        ret+=1;
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            if(visited[dx][dy]==0 and arr[dx][dy]!=0) {
                visited[dx][dy]=1;
                q.push(make_pair(dx, dy));
            }
        }
    }
}
void sub_() {

    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            
            int x,y;
            int dx,dy;
            x=i;
            y=j;
            int ice_Cnt=0;
            
            for(int k=0;k<4;k++) {
                dx=x+dir[k][0];
                dy=y+dir[k][1];
                
                if(dx<0 or dx>=N or dy<0 or dy>=N) {
                    continue;
                }
                
                if(arr[dx][dy]==0) {
                    continue;
                }
                
                ice_Cnt+=1;
            }
            
            if(ice_Cnt<=2) {
                if(arr[i][j]!=0) {
                    temp_ice[i][j]=arr[i][j]-1;
                }
                else {
                    temp_ice[i][j]=0;
                }
            }
            else {
                temp_ice[i][j]=arr[i][j];
            }
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            arr[i][j]=temp_ice[i][j];
        }
    }
    
}
void change_(int x,int y,int size_T) {
  
//    cout << x << " " << y << "\n";
    
    for(int i=0;i<size_T;i++) {
        for(int j=0;j<size_T;j++) {
            temp[j][size_T-i-1]=arr[y+i][x+j];
        }
    }
    
    for(int i=0; i<size_T; i++){
        for(int j=0; j<size_T; j++){
            arr[y+i][x+j] = temp[i][j];
        }
    }
    

}
void move_(int size_T) {
    
    for(int i=0;i<N;i+=size_T) {
        for(int j=0;j<N;j+=size_T) {
//            cout << i << " " << j << "\n";
            change_(i, j, size_T);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> Q;
    N=pow(2,N);
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }

    
    for(int i=0;i<Q;i++) {
        int data;
        cin >> data;
        data=pow(2, data);
        
        move_(data);
        sub_();
//        display_();
    }
    
    
    int tot_count=0;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            tot_count+=arr[i][j];
        }
    }
    
    int max_ice=-987654321;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(visited[i][j]==0 and arr[i][j]!=0) {
                ret=0;
                BFS_iter(i, j);
                
                if(max_ice<ret) {
                    max_ice=ret;
                }
            }
        }
    }
    
    cout << tot_count << "\n";
    if(max_ice==-987654321) {
        cout << 0 << "\n";
    }
    else {
        cout << max_ice << "\n";
    }

    return 0;
    
}

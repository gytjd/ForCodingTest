#include <iostream>
#include <queue>
using namespace std;

int N,K;
int arr[2][100004];
int visited[2][100004];
bool check_Flag;

queue<pair<int, int >> q;

int BFS_iter() {
    
    int x,y;
    int dx,dy;
    queue<pair<int, int>> temp;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        if(arr[x][y]==0) {
            continue;
        }

        dx=x;
        dy=y+1;
        
        if(dy>=N) {
            return 1;
        }
        else {
            if(dy>=0) {
                if(visited[dx][dy]==0 and arr[dx][dy]==1) {
                    visited[dx][dy]=1;
                    temp.push({dx,dy});
                }
            }
        }
        
        dx=x;
        dy=y-1;
        
        if(dy>=N) {
            return 1;
        }
        else {
            if(dy>=0) {
                if(visited[dx][dy]==0 and arr[dx][dy]==1) {
                    visited[dx][dy]=1;
                    temp.push({dx,dy});
                }
            }
        }
        
        
        dx=(x==0)?1:0;
        dy=y+K;
        
        if(dy>=N) {
            return 1;
        }
        else {
            if(dy>=0) {
                if(visited[dx][dy]==0 and arr[dx][dy]==1) {
                    visited[dx][dy]=1;
                    temp.push({dx,dy});
                }
            }
        }
    }
    
    q=temp;
    return 0;
}

void go_() {
    
    visited[0][0]=1;
    q.push({0,0});
    
    for(int i=0;i<N;i++) {
        if(BFS_iter()) {
            check_Flag=true;
            break;
        }
        arr[0][i]=0;
        arr[1][i]=0;
    }
    
    if(check_Flag) {
        cout << 1 << "\n";
    }
    else {
        cout << 0 << "\n";
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    
    for(int i=0;i<2;i++) {
        string a;
        cin >> a;
        for(int j=0;j<N;j++) {
            arr[i][j]=a[j]-'0';
        }
    }
    
    
    go_();
    
    return 0;
}

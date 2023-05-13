#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,M;
int visited[100][100];
int temp[100][100];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void display_() {
    int i,j;
    cout << "\n";

    for(i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            cout << temp[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << "\n";
    for(i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

void init_(int x,int y) {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            visited[i][j]=0;
        }
    }
    
    int dx,dy;
    
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    visited[x][y]=1;
    
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
            
            if(temp[dx][dy]==0 and visited[dx][dy]==0) {
                visited[dx][dy]=1;
                q.push(make_pair(dx, dy));
            }
        }
    }
}

int check_Cheeze(int x,int y) {
    
    int i;
    int dx,dy;
    
    for(i=0;i<4;i++) {
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        
        if(visited[dx][dy]==1) {
            return 1;
        }
    }
    
    return 0;
}

int count_() {
    int i,j;
    int count=0;
    
    for(i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            if(temp[i][j]==1) {
                count+=1;
            }
        }
    }
    
    return count;
}

void go() {
    
    vector<int> ret;
    int count=0;
    
    while(count_()!=0) {
        
        count+=1;
        ret.push_back(count_());
        
        
        init_(0,0);

        
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(temp[i][j]==1 and check_Cheeze(i, j)==1) {
                    temp[i][j]=0;
                }
            }
        }
    }
    
    cout << count << "\n";
    cout << ret[count-1] << "\n";
}
int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> temp[i][j];
        }
    }
    
    go();
    
    return 0;
}

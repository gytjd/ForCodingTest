#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char arr[104][104];
int visited[104][104];

void BFS_iter(int x,int y,vector<char> target) {
    
    int dx,dy;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N or visited[dx][dy]) {
                continue;
            }
            
            for(char temp:target) {
                if(arr[dx][dy]==temp) {
                    visited[dx][dy]=1;
                    q.push({dx,dy});
                }
            }
        }
    }
}

void go_() {
    
    int retA=0;
    int retB=0;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(visited[i][j]==0) {
                vector<char> temp;
                temp.push_back(arr[i][j]);
                BFS_iter(i, j, temp);
                retA+=1;
            }
        }
    }
    
    memset(visited,0,sizeof(visited));
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(visited[i][j]==0) {
                
                vector<char> temp;
                if(arr[i][j]=='B') {
                    temp.push_back(arr[i][j]);
                    BFS_iter(i, j, temp);
                    retB+=1;
                } else {
                    temp.push_back('R');
                    temp.push_back('G');
                    BFS_iter(i, j, temp);
                    retB+=1;
                }
            }
        }
    }
    
    cout << retA << " " << retB << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        
        string data;
        cin >> data;
        for(int j=0;j<N;j++) {
            arr[i][j]=data[j];
        }
    }
    
    go_();
    
    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

int N,M;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char arr[254][254];
bool visited[254][254];
int sheep,wolf;

void BFS_iter(int x,int y) {
    int dx,dy;
    int sheep_T=0;
    int wolf_T=0;
    
    if(arr[x][y]=='o') {
        sheep_T+=1;
    }
    else {
        wolf_T+=1;
    }
    
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y]=true;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M or arr[dx][dy]=='#' or visited[dx][dy]==true) {
                continue;
            }
            
            if(arr[dx][dy]=='.' or arr[dx][dy]=='o' or arr[dx][dy]=='v') {
                visited[dx][dy]=true;
                
                if(arr[dx][dy]=='o') {
                    sheep_T+=1;
                }
                else if(arr[dx][dy]=='v') {
                    wolf_T+=1;
                }
                
                q.push({dx,dy});
            }
        }
    }
    
    if(sheep_T>wolf_T) {
        sheep+=sheep_T;
    }
    else {
        wolf+=wolf_T;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        for(int j=0;j<M;j++) {
            arr[i][j]=a[j];
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if((arr[i][j]=='o' or arr[i][j]=='v') and visited[i][j]==false) {
                BFS_iter(i, j);
            }
        }
    }
    
    cout << sheep << " " << wolf << "\n";
    
    return 0;
}

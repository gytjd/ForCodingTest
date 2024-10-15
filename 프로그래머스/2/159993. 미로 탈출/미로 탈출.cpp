#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int N,M;
pair<int,int> start,leb,last;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char arr[104][104];
int visited[104][104];

void display_() {
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
             cout << visited[i][j] << " ";
         }
        cout << "\n";
    }
}
void BFS_iter(int x,int y) {
    
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
            
            if(dx<0 or dx>=N or dy<0 or dy>=M or arr[dx][dy]=='X') {
                continue;
            }
            
            if(visited[dx][dy]==0) {
                visited[dx][dy]=visited[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
}

int solution(vector<string> maps) {
    int answer = 0;
    
    N=maps.size();
    M=maps[0].size();
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            
            arr[i][j]=maps[i][j];
            
            if(arr[i][j]=='S') {
                start.first=i;
                start.second=j;
            }
            if(arr[i][j]=='L') {
                leb.first=i;
                leb.second=j;
            }
            if(arr[i][j]=='E') {
                last.first=i;
                last.second=j;
            }
        }
    }
    BFS_iter(start.first,start.second);
    if(visited[leb.first][leb.second]) {
        
        int temp=visited[leb.first][leb.second]-1;
        
        memset(visited,0,sizeof(visited));
        BFS_iter(leb.first,leb.second);
        
        if(visited[last.first][last.second]) {
            return temp+visited[last.first][last.second]-1;
        }
        else {
            return -1;
        }
    }
    else {
        return -1;
    }
}
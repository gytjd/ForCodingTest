#include <iostream>
#include <queue>
using namespace std;

int N,M;
bool check_Flag;
int startX,startY,endX,endY;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char arr[54][54];
int visited[54][54];

queue<pair<int, int>> q;
queue<pair<int, int>> water;

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
void BFS_water() {
    int x,y;
    int dx,dy;
    queue<pair<int, int>> temp;
    
    while(!water.empty()) {
        x=water.front().first;
        y=water.front().second;
        water.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M or arr[dx][dy]=='X') {
                continue;
            }
            
            if(visited[dx][dy]==0 and arr[dx][dy]=='.') {
                visited[dx][dy]=1;
                arr[dx][dy]='*';
                temp.push({dx,dy});
            }
        }
    }
    water=temp;
}

void BFS_iter() {
    int x,y;
    int dx,dy;
    queue<pair<int, int>> temp;
    
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
            
            if(visited[dx][dy]==0 and (arr[dx][dy]=='.' or arr[dx][dy]=='D')) {
                visited[dx][dy]=visited[x][y]+1;
                arr[dx][dy]='S';
                temp.push({dx,dy});
            }
        }
    }
    q=temp;
}
void go_() {
    
    while(!q.empty()) {
        BFS_water();
        BFS_iter();
    }
    
    if(visited[endX][endY]) {
        cout << visited[endX][endY]-1 << "\n";
    }
    else {
        cout << "KAKTUS" << "\n";
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
            
            if(a[j]=='D') {
                endX=i;
                endY=j;
            }
            
            if(a[j]=='S') {
                visited[i][j]=1;
                q.push({i,j});
            }
            
            if(a[j]=='*') {
                visited[i][j]=1;
                water.push({i,j});
            }
        }
    }
    
    go_();
    
    return 0;
}

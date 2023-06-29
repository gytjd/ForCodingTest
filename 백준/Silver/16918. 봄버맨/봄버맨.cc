#include <iostream>
#include <queue>
using namespace std;

int R,C,N;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char arr[204][204];
int visited[204][204];

queue<pair<int, int>> q;

void display_() {
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}
void fill_() {
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            arr[i][j]='O';
        }
    }
}

void BFS_iter() {
    int x,y;
    int dx,dy;
    queue<pair<int, int>> temp;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        arr[x][y]='.';
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=R or dy<0 or dy>=C) {
                continue;
            }
            
            if(arr[dx][dy]=='O') {
                arr[dx][dy]='.';
            }
        }
    }
    
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(arr[i][j]=='O') {
                q.push({i,j});
            }
        }
    }
}

void go_() {
    int count_T=1;
    
    while(count_T<N) {
        fill_();
        count_T+=1;
        
        if(count_T==N) {
            break;
        }
        BFS_iter();
        count_T+=1;
    }
    
    display_();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> R >> C >> N;
    
    for(int i=0;i<R;i++) {
        string temp;
        cin >> temp;
        
        for(int j=0;j<temp.size();j++) {
            arr[i][j]=temp[j];
            
            if(arr[i][j]=='O') {
                q.push({i,j});
            }
        }
    }
    
    go_();
    
    return 0;
}

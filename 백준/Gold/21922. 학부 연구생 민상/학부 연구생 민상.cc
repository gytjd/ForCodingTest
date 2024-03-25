#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 2004

using namespace std;

int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[MAX_SIZE][MAX_SIZE];
int visited[4][MAX_SIZE][MAX_SIZE];
vector<pair<int,int>> start;


void display_() {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            bool check_Flag=false;
            for(int k=0;k<4;k++) {
                if(visited[k][i][j]) {
                    check_Flag=true;
                    break;
                }
            }
            
            cout << (check_Flag==false?0:1) << " ";
        }
        cout << "\n";
    }
}

int change_Dir(int curr, int next) {
    int result = -1;

    if (curr == 0) {
        switch (next) {
            case 1:
                result = 2;
                break;
            case 2:
                result = 0;
                break;
            case 3:
                result = 3;
                break;
            case 4:
                result = 1;
                break;
        }
    } else if (curr == 1) {
        switch (next) {
            case 1:
                result = 1;
                break;
            case 2:
                result = 3;
                break;
            case 3:
                result = 2;
                break;
            case 4:
                result = 0;
                break;
        }
    } else if (curr == 2) {
        switch (next) {
            case 1:
                result = 0;
                break;
            case 2:
                result = 2;
                break;
            case 3:
                result = 1;
                break;
            case 4:
                result = 3;
                break;
        }
    } else {
        switch (next) {
            case 1:
                result = 3;
                break;
            case 2:
                result = 1;
                break;
            case 3:
                result = 0;
                break;
            case 4:
                result = 2;
                break;
        }
    }

    return result;
}

void BFS_iter(int x,int y) {
    
    int dd,dx,dy;
    queue<pair<int,int>> q;
    q.push({x,y});
    
    for(int i=0;i<4;i++) {
        dd=i;dx=x;dy=y;
        visited[i][x][y]=1;
        
        while(true) {
            dx=dx+dir[dd][0];
            dy=dy+dir[dd][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                break;
            }
            
            if(visited[dd][dx][dy]==0) {
                visited[dd][dx][dy]=1;
                if(arr[dx][dy]!=0 and arr[dx][dy]!=9) dd=change_Dir(dd, arr[dx][dy]);
            }
            else {
                break;
            }
                
        }
    }
}

void go_() {
    
    for(int i=0;i<start.size();i++) {
//        cout << start[i].first << " " << start[i].second << "\n";
        BFS_iter(start[i].first, start[i].second);
    }
    
    int answer=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            for(int k=0;k<4;k++) {
                if(visited[k][i][j]) {
                    answer+=1;
                    break;
                }
            }
        }
    }
    
    cout << answer << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            
            if(arr[i][j]==9) {
                start.push_back({i,j});
            }
        }
    }
    
    go_();
    
    return 0;
}

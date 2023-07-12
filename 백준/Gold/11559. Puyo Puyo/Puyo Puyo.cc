#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char arr[12][6];
int visited[12][6];
vector<pair<int, int>> v;
vector<pair<int, int>> tmp;

void display_() {
    
    cout << "\n";
    for(int i=0;i<12;i++) {
        for(int j=0;j<6;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int BFS_iter(int x,int y) {
    
    int tmp_Ret=0;
    char curr=arr[x][y];
    int dx,dy;
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        tmp_Ret+=1;
        tmp.push_back({x,y});
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=12 or dy<0 or dy>=6 or arr[dx][dy]=='.') {
                continue;
            }
            
            if(visited[dx][dy]==0 and arr[dx][dy]==curr) {
                visited[dx][dy]=1;
                q.push({dx,dy});
            }
        }
    }
    
    return tmp_Ret;
}

void down_() {
    for(int i=10;i>=0;i--) {
        for(int j=0;j<6;j++) {
            if(arr[i][j]!='.') {
                for(int k=i+1;k<12;k++) {
                    if(arr[k][j]=='.') {
                        arr[k][j]=arr[k-1][j];
                        arr[k-1][j]='.';
                    }
                }
                
            }
        }
    }
}

void go_() {
    
    int ret=0;
    
    while(true) {
        bool check_Flag=false;
        memset(visited, 0, sizeof(visited));
        
        for(int i=0;i<12;i++) {
            for(int j=0;j<6;j++) {
                if(arr[i][j]!='.' and visited[i][j]==0) {
                    tmp.clear();
                    if(BFS_iter(i, j)>=4) {
                        check_Flag=true;
                        for(int k=0;k<tmp.size();k++) {
                            arr[tmp[k].first][tmp[k].second]='.';
                        }
                    }
                }
            }
        }
        
        if(!check_Flag) {
            cout << ret << "\n";
            break;
        }
        
        down_();
        ret+=1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i=0;i<12;i++) {
        string a;
        cin >> a;
        for(int j=0;j<6;j++) {
            arr[i][j]=a[j];
        }
    }
    
    go_();
    
    
    return 0;
}

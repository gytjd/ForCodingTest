#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int ret;
int T,N,W,H;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[20][20];
int tempArr[20][20];
int visited[20][20];
int check[15];

void display_() {
    
    cout << "\n";
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            cout << tempArr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int check_Idx(int idx) {
    
    for(int i=0;i<H;i++) {
        if(tempArr[i][idx] > 0) {
            return i;
        }
    }
    return -1;
}


void bomb_(int idx) {
    
    
    int x=check_Idx(idx); int y=idx;
    
    if (x < 0) return;
    if (tempArr[x][y] == 0) return;
    
    int dx,dy,num;
    visited[x][y]=1;
    
    queue<pair<int,int>> q;
    q.push({x,y});
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        num=tempArr[x][y]; tempArr[x][y]=0;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x;
            dy=y;
            for(int j=0;j<num-1;j++) {
                dx=dx+dir[i][0];
                dy=dy+dir[i][1];
                
                if(dx<0 or dx>=H or dy<0 or dy>=W) {
                    break;
                }
                
                if(visited[dx][dy] or tempArr[dx][dy]<=0) continue;
                
                visited[dx][dy]=1;
                q.push({dx,dy});
            }
        }
    }
}

void down_() {
    
    for(int i=0;i<W;i++) {
        
        vector<int> temp;
        for(int j=H-1;j>=0;j--) {
            if(tempArr[j][i]) temp.push_back(tempArr[j][i]);
        }
        
        for(int j=0;j<H;j++) {
            if(j<temp.size()) tempArr[H-j-1][i]=temp[j];
            else tempArr[H-j-1][i]=0;
        }
    }
}

int go_() {
    
    int tempRet=0;
    
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            tempArr[i][j]=arr[i][j];
        }
    }
    
    for(int i=0;i<N;i++) {
        memset(visited, 0, sizeof(visited));
        bomb_(check[i]);
        down_();
    }
    
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            if(tempArr[i][j]) tempRet+=1;
        }
    }
    
    return tempRet;
}

void DFS_permu(int curr) {
    
    if(curr==N) {
        ret=min(ret,go_());
        return;
    }
    
    for(int i=0;i<W;i++) {
        check[curr]=i;
        DFS_permu(curr+1);
    }
}

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int test_case=1;test_case<=T;test_case++) {
        
        cin >> N >> W >> H;
        
        for(int i=0;i<H;i++) {
            for(int j=0;j<W;j++) {
                cin >> arr[i][j];
            }
        }
        
        ret=987654321;
        DFS_permu(0);
        cout << "#" << test_case << " " << ret << "\n";
    }
    
    return 0;
}
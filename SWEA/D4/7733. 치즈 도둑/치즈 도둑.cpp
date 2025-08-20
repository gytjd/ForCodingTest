#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int T,N;
int ret;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[104][104];
int visited[104][104];

vector<pair<int,int>> v[104];
int temp[104][104];

void init_() {
    
    ret=1;
    for(int i=0;i<=100;i++) {
        v[i].clear();
    }
    memset(visited,0,sizeof(visited));
}

void BFS_iter(int x,int y) {
    
    int dx,dy;
    queue<pair<int,int>> q;
    q.push({x,y});
    temp[x][y]=1;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N or temp[dx][dy] or visited[dx][dy]) {
                continue;
            }
            
            temp[dx][dy]=1;
            q.push({dx,dy});
        }
    }
    
}
void go_() {
    
    for(int i=1;i<=100;i++) {
        for(pair<int,int> check:v[i]) {
            visited[check.first][check.second]=1;
        }
        
        int tempCnt=0;
        memset(temp,0,sizeof(temp));
        
        for(int j=0;j<N;j++) {
            for(int k=0;k<N;k++) {
                if(temp[j][k]==0 and visited[j][k]==0) {
                    BFS_iter(j, k);
                    tempCnt+=1;
                }
            }
        }
        ret=max(ret,tempCnt);
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int test_case=1;test_case<=T;test_case++) {
        
        init_();
        
        cin >> N;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                int data;
                cin >> data;
                v[data].push_back({i,j});
            }
        }
        
        go_();
        cout << "#" << test_case << " " << ret << "\n";
    }
    
    return 0;
}
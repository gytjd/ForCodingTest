#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

int N,L,R;
int temp[51][51];
int visited[51][51];

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

bool check_Flag=false;

void init_() {
    for(int i=0;i<51;i++) {
        for(int j=0;j<51;j++) {
            visited[i][j]=0;
        }
    }
}


void BFS_iter(int x,int y) {
    
    int dx,dy;
    queue<pair<int, int>>q;
    vector<int> tmp;
    vector<pair<int, int>> idx;
    
    visited[x][y]=1;
    q.push(make_pair(x, y));
    tmp.push_back(temp[x][y]);
    idx.push_back(make_pair(x, y));
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=N) {
                continue;
            }
            
            int tot=abs(temp[dx][dy]-temp[x][y]);
            
            if(tot>=L and tot<=R) {
                if(visited[dx][dy]==0) {
                    check_Flag=true;
                    visited[dx][dy]=1;
                    q.push(make_pair(dx, dy));
                    
                    tmp.push_back(temp[dx][dy]);
                    idx.push_back(make_pair(dx, dy));
                }
            }
        }
    }
    
    int sum_t=0;
    for(int i=0;i<tmp.size();i++) {
        sum_t+=tmp[i];
    }
    sum_t/=tmp.size();
    
    for(int i=0;i<tmp.size();i++) {
        temp[idx[i].first][idx[i].second]=sum_t;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> L >> R;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> temp[i][j];
        }
    }
    int tot=0;
    
    while(1) {
        
        check_Flag=false;
    
        
        init_();
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(visited[i][j]==0) {
                    BFS_iter(i, j);
                }
            }
        }
        
        if(check_Flag==false) {
            break;
        }
        
        tot+=1;
        
    }
    cout << tot << "\n";
    
    return 0;
}

#include <iostream>
#include <queue>

using namespace std;

int R,C;
char temp[1004][1004];
int user_visited[1004][1004];
int fire_visited[1004][1004];
int tot=0;


int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

queue<pair<int, int>> user;
queue<pair<int,int>> fire;

void init_() {
    
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(temp[i][j]=='J') {
                user.push(make_pair(i, j));
                user_visited[i][j]=1;
            }
            else if(temp[i][j]=='F') {
                fire.push(make_pair(i, j));
                fire_visited[i][j]=1;
            }
        }
    }

}

void BFS_user() {
    
    int x,y;
    int dx,dy;
    
    while(!user.empty()) {
        x=user.front().first;
        y=user.front().second;

        user.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=R or dy<0 or dy>=C) {
                continue;
            }
            
            if(user_visited[dx][dy]==0 and temp[dx][dy]=='.') {
                user_visited[dx][dy]=user_visited[x][y]+1;
                user.push(make_pair(dx, dy));
            }
        }
    }
}

void BFS_fire() {
    
    int x,y;
    int dx,dy;
    
    while(!fire.empty()) {
        x=fire.front().first;
        y=fire.front().second;
        fire.pop();
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=R or dy<0 or dy>=C) {
                continue;
            }
            
            if(fire_visited[dx][dy]==0 and (temp[dx][dy]=='.' or temp[dx][dy]=='J')) {
                fire_visited[dx][dy]=fire_visited[x][y]+1;
                fire.push(make_pair(dx, dy));
            }
        }
    }
}

void cal_tot_X(int idx) {
    
    for(int i=0;i<C;i++) {
        
        if(user_visited[idx][i]!=0) {
            
            if(user_visited[idx][i]<fire_visited[idx][i] or fire_visited[idx][i]==0) {
                if(tot==0) {
                    tot=user_visited[idx][i];
                }
                else {
                    if(tot>user_visited[idx][i]) {
                        tot=user_visited[idx][i];
                    }
                }
            }
        }
    }
}

void cal_tot_Y(int idx) {
    
    for(int i=0;i<R;i++) {
        
        if(user_visited[i][idx]!=0) {
            
            if(user_visited[i][idx]<fire_visited[i][idx] or fire_visited[i][idx]==0) {
                if(tot==0) {
                    tot=user_visited[i][idx];
                }
                else {
                    if(tot>user_visited[i][idx]) {
                        tot=user_visited[i][idx];
                    }
                }
            }
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> R >> C;
    for(int i=0;i<R;i++) {
        string a;
        cin >> a;
        for(int j=0;j<a.size();j++) {
            temp[i][j]=a[j];
        }
    }
    
    init_();
    BFS_user();
    BFS_fire();
    
    
    cal_tot_X(0);
    cal_tot_X(R-1);
    cal_tot_Y(0);
    cal_tot_Y(C-1);
    
    
    
    if(tot==0) {
        cout << "IMPOSSIBLE" << "\n";
    }
    else {
        cout << tot << "\n";
    }
    
    
    return 0;
}

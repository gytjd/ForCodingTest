#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int x,y,weight;
};

int N,M,K;
int arr[14][14];
int temp[14][14];
int dir[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

deque<int> q[14][14];
vector<Node> alive;
vector<Node> dead;


void spring_() {
    alive.clear();
    dead.clear();
    int temp;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(q[i][j].size()!=0) {
                sort(q[i][j].begin(), q[i][j].end());
                
                while(!q[i][j].empty()) {
                    temp=q[i][j].front();
                    q[i][j].pop_front();
                    
                    if(temp<=arr[i][j]) {
                        arr[i][j]-=temp;
                        temp+=1;
                        alive.push_back({i,j,temp});
                    }
                    else {
                        dead.push_back({i,j,temp});
                    }
                }
            }
            
        }
    }
}

void summer_() {
    
    for(Node temp:dead) {
        arr[temp.x][temp.y]+=temp.weight/2;
    }
}

void fall_() {
    
    int x,y;
    int dx,dy;
    
    for(Node temp:alive) {
        q[temp.x][temp.y].push_back(temp.weight);

        if(temp.weight%5==0) {
            x=temp.x;
            y=temp.y;
            
            for(int i=0;i<8;i++) {
                dx=x+dir[i][0];
                dy=y+dir[i][1];
                
                if(dx<0 or dx>=N or dy<0 or dy>=N) {
                    continue;
                }
                
                q[dx][dy].push_back(1);
            }
        }
    }
}

void winter_() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            arr[i][j]+=temp[i][j];
        }
    }
}
void go_() {
    
    for(int i=0;i<K;i++) {
        spring_();
        summer_();
        fall_();
        winter_();
    }
    
    int result=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            result+=q[i][j].size();
        }
    }
    
    cout << result << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> K;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> temp[i][j];
            arr[i][j]=5;
        }
    }
    
    for(int i=0;i<M;i++) {
        int x,y,weight;
        cin >> x >> y >> weight;
        q[x-1][y-1].push_back(weight);
    }
    
    go_();

    return 0;
}


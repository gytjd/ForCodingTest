#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,K;
int A[14][14];
int curr[14][14];
int dir[8][2]={{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0}};

deque<int> q[14][14];
vector<int> alive[14][14];
vector<int> dead[14][14];

void display_() {
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cout << curr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void init_() {
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            curr[i][j]=5;
        }
    }
}

void spring_() {
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            
            sort(q[i][j].begin(),q[i][j].end());
            while(!q[i][j].empty()) {
                
                if(curr[i][j]>=q[i][j].front()) {
                    curr[i][j]-=q[i][j].front();
                    alive[i][j].push_back(q[i][j].front()+1);
                } else {
                    dead[i][j].push_back(q[i][j].front());
                }
                q[i][j].pop_front();
            }
        }
    }
}

void summer_() {
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            
            for(int temp:dead[i][j]) {
                curr[i][j]+=(temp/2);
            }
            dead[i][j].clear();
        }
    }
}

void fall_() {
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            
            for(int temp:alive[i][j]) {
                
                q[i][j].push_back(temp);
                if(temp%5==0) {
                    
                    for(int k=0;k<8;k++) {
                        int dx=i+dir[k][0];
                        int dy=j+dir[k][1];
                        
                        if(dx<=0 or dx>N or dy<=0 or dy>N) {
                            continue;
                        }
                        
                        q[dx][dy].push_back(1);
                    }
                }
            }
            alive[i][j].clear();
        }
    }
}

void winter_() {
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            curr[i][j]+=A[i][j];
        }
    }
}

int cal_() {
    
    int ret=0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            ret+=q[i][j].size();
        }
    }
    
    return ret;
}
void go_() {
    
    init_();
    
    for(int i=0;i<K;i++) {
        spring_();
        summer_();
        fall_();
        winter_();
    }
    
    cout << cal_() << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> K;
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> A[i][j];
        }
    }
    
    for(int i=0;i<M;i++) {
        int x,y,o;
        cin >> x >> y >> o;
        q[x][y].push_back(o);
    }
    
    go_();
    
    return 0;
}

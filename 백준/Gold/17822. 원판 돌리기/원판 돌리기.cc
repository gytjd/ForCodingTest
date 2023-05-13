#include <iostream>
#include <queue>
using namespace std;

int N,M,T;
deque<int> q[54];

void display_() {
    for(int i=1;i<=N;i++) {
        for(int j=0;j<M;j++) {
            cout << q[i][j] << " ";
        }
        cout << "\n";
    }
}
void turn_(int idx,int dir,int cnt_T) {
    
    if(dir==1) {
        
        for(int i=0;i<cnt_T;i++) {
            q[idx].push_back(q[idx].front());
            q[idx].pop_front();
        }
    }
    else {
        
        for(int i=0;i<cnt_T;i++) {
            q[idx].push_front(q[idx].back());
            q[idx].pop_back();
        }
    }
}

int cal_() {
    
    deque<int> temp[N+1];
    for(int i=1;i<=N;i++) {
        temp[i]=q[i];
    }
    
    int left,right;
    int cnt_T=0;
    for(int i=1;i<=N;i++) {
        for(int j=0;j<M;j++) {
            
            
            if(q[i][j]==-1) {
                continue;
            }
            
            left=j-1;
            if(left<0) {
                left=M-1;
            }
            right=j+1;
            if(right>=M) {
                right=0;
            }
            
            if(i==1) {
                if(q[i][left]==q[i][j] or q[i][right]==q[i][j] or q[i+1][j]==q[i][j]) {
                    cnt_T+=1;
                    temp[i][j]=-1;
                }
            }
            else if(i==N) {
                
                if(q[i][left]==q[i][j] or q[i][right]==q[i][j] or q[i-1][j]==q[i][j]) {
                    cnt_T+=1;
                    temp[i][j]=-1;
                }
            }
            else {
                
                if(q[i][left]==q[i][j] or q[i][right]==q[i][j] or q[i+1][j]==q[i][j] or q[i-1][j]==q[i][j]) {
                    
                    cnt_T+=1;
                    temp[i][j]=-1;
                }
            }
        }
    }
    
    for(int i=1;i<=N;i++) {
        q[i]=temp[i];
    }
    
    return cnt_T;
}

void avg_() {
    
    float sum_T=0;
    float cnt_T=0;
    for(int i=1;i<=N;i++) {
        for(int j=0;j<M;j++) {
            
            if(q[i][j]==-1) {
                continue;
            }
            
            sum_T+=q[i][j];
            cnt_T+=1;
        }
    }
    
    sum_T/=cnt_T;
    for(int i=1;i<=N;i++) {
        for(int j=0;j<M;j++) {
            
            if(q[i][j]==-1) {
                continue;
            }
            
            if(q[i][j]<sum_T) {
                q[i][j]+=1;
            }
            else if(q[i][j]>sum_T) {
                q[i][j]-=1;
                
                if(q[i][j]<1) {
                    q[i][j]=-1;
                }
            }
        }
    }
}
void go_() {
    
    for(int i=0;i<T;i++) {
        int idx,dir,cnt_T;
        cin >> idx >> dir >> cnt_T;
        
        
        for(int j=idx;j<=N;j+=idx) {
            turn_(j, dir,cnt_T);
        }
        
        
        if(!cal_()) {
            avg_();
        }

    }
    
    int temp_S=0;
    for(int i=1;i<=N;i++) {
        for(int j=0;j<M;j++) {
            
            if(q[i][j]==-1) {
                continue;
            }
            temp_S+=q[i][j];
        }
    }
    
    cout << temp_S << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> T;
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            int data;
            cin >> data;
            q[i].push_back(data);
        }
    }
    
    go_();
    
    return 0;
}

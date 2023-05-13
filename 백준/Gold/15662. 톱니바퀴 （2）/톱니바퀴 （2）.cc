#include <iostream>
#include <queue>
using namespace std;

int N,K;
deque<int> q[1004];
int dir_T[2]={1,-1};

void turn_dir(int start,int dir) {
    if(dir==1) {
        q[start].push_front(q[start].back());
        q[start].pop_back();
    }
    else {
        q[start].push_back(q[start].front());
        q[start].pop_front();
    }
}
void turn_(int start,int dir) {
    
    int visited[1004]={0,};
    int temp_start;
    
    visited[start]=1;
    queue<pair<int,int>> temp_q;
    queue<pair<int, int>> ret;
    ret.push({start,dir});
    temp_q.push({start,dir});
    
    while(!temp_q.empty()) {
        start=temp_q.front().first;
        dir=temp_q.front().second;
        temp_q.pop();
        
        for(int i=0;i<2;i++) {
            temp_start=start+dir_T[i];
            
            if(temp_start<=0 or temp_start>N) {
                continue;
            }
            
            if(visited[temp_start]==0) {
                
                if(i==0) {
                    if(q[start][2]!=q[temp_start][6]) {
                        
                        if(dir==1) {
                            temp_q.push({temp_start,-1});
                            ret.push({temp_start,-1});
                        }
                        else {
                            temp_q.push({temp_start,1});
                            ret.push({temp_start,1});
                        }
                        visited[temp_start]=1;
                    }
                }
                else {
                    if(q[start][6]!=q[temp_start][2]) {
                        
                        if(dir==1) {
                            temp_q.push({temp_start,-1});
                            ret.push({temp_start,-1});
                        }
                        else {
                            temp_q.push({temp_start,1});
                            ret.push({temp_start,1});
                        }
                        
                        visited[temp_start]=1;
                    }
                }
            }
        }
    }
    
    
    int r_Size=ret.size();
    
    for(int i=0;i<r_Size;i++) {
        turn_dir(ret.front().first, ret.front().second);
        ret.pop();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=1;i<=N;i++) {
        string a;
        cin >> a;
        
        for(char temp:a) {
            q[i].push_back(temp-'0');
        }
    }
    
    cin >> K;
    for(int i=0;i<K;i++) {
        int start,dir;
        cin >> start >> dir;
        turn_(start, dir);
    }
    
    int ret=0;
    for(int i=1;i<=N;i++) {
        
        if(q[i][0]==1) {
            ret+=1;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}

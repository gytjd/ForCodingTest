#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

int N,M;
vector<int> temp_Num;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[1004][1004];
int visited[1004][1004];
int answer[1004][1004];

void display_() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

int BFS_init_(int x,int y,int curr) {
    int dx,dy;
    int temp_Cnt=0;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=curr;
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        temp_Cnt+=1;
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M or arr[dx][dy]==1) {
                continue;
            }
            
            if(visited[dx][dy]==0) {
                visited[dx][dy]=curr;
                q.push({dx,dy});
            }
        }
    }
    return temp_Cnt;
}

void init_() {
    int temp_Cnt=1;
    temp_Num.push_back(0);
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(visited[i][j]==0 and arr[i][j]==0) {
                temp_Num.push_back(BFS_init_(i, j, temp_Cnt++));
            }
        }
    }
}

int BFS_check(int x,int y) {
    
    int dx,dy;
    int temp_Ret=1;
    unordered_map<int,bool> m;
    
    for(int i=0;i<4;i++) {
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        
        if(dx<0 or dx>=N or dy<0 or dy>=M) {
            continue;
        }
        
        if(m[visited[dx][dy]]==0) {
            m[visited[dx][dy]]=1;
            temp_Ret+=temp_Num[visited[dx][dy]];
        }
    }
    return temp_Ret;
}
void go_() {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr[i][j]==0) {
                answer[i][j]=0;
            }
            else {
                answer[i][j]=BFS_check(i, j);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        for(int j=0;j<M;j++) {
            arr[i][j]=a[j]-'0';
        }
    }
    
    init_();
    go_();
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << answer[i][j]%10;
        }
        cout << "\n";
    }
//    display_();
//    for(int i=0;i<temp_Num.size();i++) {
//        cout << i << " " <<  temp_Num[i] << '\n';
//    }
    
    
    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

int ret;
int arr[6][3];
int visited[6][3];
vector<pair<int,int>> v;

void init_() {
    
    for(int i=0;i<6;i++) {
        for(int j=i+1;j<6;j++) {
            v.push_back({i,j});
        }
    }
}

void display_() {
    
    for(int i=0;i<6;i++) {
        for(int j=0;j<3;j++) {
            cout << visited[i][j] << " ";
        }
    }
    cout << "\n";
}

bool cal_() {
    
    for(int i=0;i<6;i++) {
        for(int j=0;j<3;j++) {
            if(arr[i][j]!=visited[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void DFS_recur(int curr) {
    
    if(ret) {
        return;
    }
    
    if(curr==15) {
        
        if(cal_()) {
            ret=1;
        }
        return;
    }
    
    visited[v[curr].first][0]+=1; // 승리
    visited[v[curr].second][2]+=1;
    DFS_recur(curr+1);
    visited[v[curr].first][0]-=1;
    visited[v[curr].second][2]-=1;
    
    
    visited[v[curr].first][1]+=1; // 무승부
    visited[v[curr].second][1]+=1;
    DFS_recur(curr+1);
    visited[v[curr].first][1]-=1;
    visited[v[curr].second][1]-=1;
    
    
    visited[v[curr].first][2]+=1; // 패배
    visited[v[curr].second][0]+=1;
    DFS_recur(curr+1);
    visited[v[curr].first][2]-=1;
    visited[v[curr].second][0]-=1;
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    init_();
    
    for(int i=0;i<4;i++) {
        
        for(int j=0;j<6;j++) {
            for(int k=0;k<3;k++) {
                cin >> arr[j][k];
            }
        }
        ret=0;
        DFS_recur(0);
        cout << ret << " ";
    }
    cout << "\n";
}

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int answer;
int visited[6][3];
int arr[6][3];
vector<pair<int,int>> v;

void init_() {
    
    for(int i=0;i<6;i++) {
        for(int j=i+1;j<6;j++) {
            v.push_back({i,j});
        }
    }
}

void DFS_recur(int cnt) {
    
    if(cnt==15) {
        for(int i=0;i<6;i++) {
            for(int j=0;j<3;j++) {
                if(visited[i][j]!=arr[i][j]) {
                    return;
                }
            }
        }
        answer=1;
        return;
    }
    
    
    // A 가 이김 B가 짐
    visited[v[cnt].first][0]+=1;
    visited[v[cnt].second][2]+=1;
    DFS_recur(cnt+1);
    visited[v[cnt].first][0]-=1;
    visited[v[cnt].second][2]-=1;
    
    // A B 무승부
    visited[v[cnt].first][1]+=1;
    visited[v[cnt].second][1]+=1;
    DFS_recur(cnt+1);
    visited[v[cnt].first][1]-=1;
    visited[v[cnt].second][1]-=1;
    
    // A가 짐 B가 이김
    visited[v[cnt].first][2]+=1;
    visited[v[cnt].second][0]+=1;
    DFS_recur(cnt+1);
    visited[v[cnt].first][2]-=1;
    visited[v[cnt].second][0]-=1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    init_();
    
    for(int i=0;i<4;i++) {
        
        for(int j=0;j<6;j++) {
            for(int k=0;k<3;k++) {
                visited[j][k]=0;
                cin >> arr[j][k];
            }
        }
        
        answer=0;
        DFS_recur(0);
        
        cout << answer << " ";
    }

    
    return 0;
}


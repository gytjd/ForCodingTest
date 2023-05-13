#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int temp[26][26];
int visited[26][26];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int N;
int count_fun=0;

vector<int> result;

void BFS_iter(int x,int y) {
    visited[x][y]=1;
    
    int dx,dy;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
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
            
            if(temp[dx][dy]==1 and visited[dx][dy]==0) {
                count_fun+=1;
                visited[dx][dy]=1;
                q.push(make_pair(dx, dy));
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        for(int j=0;j<a.size();j++) {
            temp[i][j]=a[j]-'0';
        }
    }
    
    int count_T=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            
            if(temp[i][j]==1 and visited[i][j]==0) {
                count_T+=1;
                
                BFS_iter(i, j);
                result.push_back(count_fun+1);
                count_fun=0;
            }
        }
    }
    
    sort(result.begin(),result.end());
    cout << count_T << "\n";
    for(int i:result) {
        cout << i << "\n";
    }
    
    return 0;
}

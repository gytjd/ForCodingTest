#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector<string> arr;
int visited[104][104];

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int BFS_iter(int x,int y,char data) {
    
    int count_tmp=0;
    
    int dx,dy;
    visited[x][y]=1;
    queue<pair<int, int >>q;
    q.push(make_pair(x, y));
    
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        count_tmp+=1;
        
        for(int i=0;i<4;i++) {
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            
            if(dx<0 or dx>=N or dy<0 or dy>=M) {
                continue;
            }
            
            if(arr[dx][dy]==data and visited[dx][dy]==0) {
                visited[dx][dy]=1;
                q.push(make_pair(dx, dy));
            }
        }
    }
    
    return count_tmp;
}

void cal_(char data) {
    
    int result=0;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            
            if(arr[i][j]==data and visited[i][j]==0) {
                int q=BFS_iter(i, j, data);
                result+=q*q;
            }
        }
    }
    
    cout << result << " ";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> M >> N;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        
        arr.push_back(a);
    }
    
    cal_('W');
    cal_('B');
    cout << "\n";
    
    return 0;
}

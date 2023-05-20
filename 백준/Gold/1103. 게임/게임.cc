#include <iostream>
#include <cstring>
using namespace std;

int N,M;
char arr[54][54];
int dp[54][54];
bool visited[54][54];

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int go_(int x,int y) {
    
    if(x<0 or x>=N or y<0 or y>=M or arr[x][y]=='H') {
        return 0;
    }
    
    if(visited[x][y]) {
        cout << -1 << "\n";
        exit(0);
    }
    
    int &ret=dp[x][y];
    if(ret!=-1) {
        return ret;
    }
    visited[x][y]=true;
    ret=0;
    int dx,dy;
    for(int i=0;i<4;i++) {
        dx=x+(dir[i][0]*(arr[x][y]-'0'));
        dy=y+(dir[i][1]*(arr[x][y]-'0'));
        ret=max(ret,go_(dx, dy)+1);
    }
    visited[x][y]=false;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        for(int j=0;j<a.size();j++) {
            arr[i][j]=a[j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    cout << go_(0, 0) << "\n";
    
    return 0;
}

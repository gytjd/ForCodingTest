#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<string> arr;
int N,M;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int visited[26];
int max_depth=-987654321;

void DFS_recur(int x,int y,int depth) {
    
    int dx,dy;

    
    if(depth>max_depth) {
        max_depth=depth;
    }
    
    for(int i=0;i<4;i++) {
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        
        if(dx<0 or dx>=N or dy<0 or dy>=M) {
            continue;
        }
        
        if(visited[arr[dx][dy]-65]==0) {
            visited[arr[dx][dy]-65]=1;
            DFS_recur(dx, dy,depth+1);
            visited[arr[dx][dy]-65]=0;
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
        arr.push_back(a);
    }

    visited[arr[0][0]-65]=1;
    DFS_recur(0, 0, 1);
    cout << max_depth << "\n";
    
    return 0;
}

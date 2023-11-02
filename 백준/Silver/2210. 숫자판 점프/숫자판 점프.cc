#include <iostream>
#include <queue>
#include <map>
using namespace std;

int ret;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char arr[5][5];
map<string, int> m;

void DFS_recur(int x,int y,string temp,int count) {
    
    if(count==5) {
        if(m[temp]==0) {
            m[temp]+=1;
            ret+=1;
        }
        return;
    }
    
    int dx,dy;
    for(int i=0;i<4;i++) {
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        
        if(dx<0 or dx>=5 or dy<0 or dy>=5) {
            continue;
        }
        DFS_recur(dx, dy, temp+arr[dx][dy],count+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cin >> arr[i][j];
        }
    }
    

    
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            string temp="";
            temp+=arr[i][j];
            DFS_recur(i, j,temp ,0);
        }
    }
    
    cout << ret << "\n";
    
    
    return 0;
}

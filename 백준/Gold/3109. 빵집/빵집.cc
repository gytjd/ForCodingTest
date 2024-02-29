#include <iostream>

using namespace std;

int R,C;
int answer;
bool check_Flag;
int dir[3][2]={{-1,1},{0,1},{1,1}};
int arr[10004][504];
int visited[10004][504];

void display_() {
    cout << "\n";
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}
void DFS_recur(int x,int y) {
    int dx,dy;
    visited[x][y]=1;
    
    if(y==C-1) {
        answer+=1;
        check_Flag=true;
        return;
    }
    
    for(int i=0;i<3;i++) {
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        
        if(dx<0 or dx>=R or dy<0 or dy>=C or arr[dx][dy]=='x') {
            continue;
        }
        
        if(visited[dx][dy]==0) {
            DFS_recur(dx, dy);
            if(check_Flag) {
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> R >> C;
    
    for(int i=0;i<R;i++) {
        string a;
        cin >> a;
        for(int j=0;j<C;j++) {
            arr[i][j]=a[j];
        }
    }
    
    for(int i=0;i<R;i++) {
        check_Flag=false;
        DFS_recur(i, 0);
//        display_();
    }
    
    cout << answer << "\n";
    
    return 0;
}

#include <iostream>

using namespace std;

int N,M;

bool check_Flag;
int ret;
int dir[3][2]={{-1,1},{0,1},{1,1}};
char arr[10004][504];
int visited[10004][504];

void display_() {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void DFS_recur(int x,int y) {
    
    int dx,dy;
    
    if(y==M-1) {
        ret+=1;
        check_Flag=true;
        return;
    }
    
    for(int i=0;i<3;i++) {
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        
        if(dx<0 or dx>=N or dy<0 or dy>=M or visited[dx][dy]) {
            continue;
        }
        
        if(arr[dx][dy]=='.' and !check_Flag) {
            visited[dx][dy]=1;
            DFS_recur(dx, dy);
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        
        string data;
        cin >> data;
        for(int j=0;j<M;j++) {
            arr[i][j]=data[j];
        }
    }
    
    for(int i=0;i<N;i++) {
        if(arr[i][0]=='.') {
            check_Flag=false;
            DFS_recur(i, 0);
        }
    }
//    display_();
    
    cout << ret << "\n";
    
    return 0;
}

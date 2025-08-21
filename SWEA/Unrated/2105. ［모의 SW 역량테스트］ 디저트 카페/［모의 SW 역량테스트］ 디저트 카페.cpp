#include <iostream>
#include <algorithm>

using namespace std;

int T,N;
int ret;
int dir[4][2]={{1,1},{1,-1},{-1,-1},{-1,1}};
int arr[24][24];
int visited[104];

void display_() {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            printf("%2d ",arr[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";
}

void DFS_recur(int curr,int currIdx,int currX,int currY,int endX,int endY) {
    
//    cout << curr << "\n";
//    display_();
    
    int dx,dy,tempIdx=currIdx;
    
    for(int i=0;i<2;i++) {
        int tempIdx = (i==0 ? currIdx : currIdx+1);  // 다음 방향 꺾기
        if(tempIdx >= 4) continue;                  // 0~3 방향만 허용
        
        dx=currX+dir[tempIdx][0];
        dy=currY+dir[tempIdx][1];
        
        if(dx==endX and dy==endY) {
            ret=max(ret,curr);
            continue;
        }

        if(dx>=0 and dx<N and dy>=0 and dy<N) {
            
            if(visited[arr[dx][dy]]==0) {
                visited[arr[dx][dy]]=1;
                DFS_recur(curr+1, tempIdx, dx, dy, endX, endY);
                visited[arr[dx][dy]]=0;
            }
        }
        
    }
}

void go_() {
    
    for(int i=0;i<N-2;i++) {
        for(int j=1;j<N-1;j++) {
            visited[arr[i][j]]=1;
            DFS_recur(1, 0, i, j, i, j);
            visited[arr[i][j]]=0;
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int test_case=1;test_case<=T;test_case++) {
        
        cin >> N;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cin >> arr[i][j];
            }
        }
        
        ret=-1;
        go_();
        cout << "#" << test_case << " " << ret << "\n";
    }
    
    return 0;
}

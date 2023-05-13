#include <iostream>
#include <queue>
using namespace std;

int N;
int dir[3][2]={{0,1},{1,1},{1,0}};
int arr[36][36];
long long visited[36][36][3];

struct Node {
    int curr,x,y;
};

void display_() {
    
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

void go_() {
    
    visited[0][1][0]=1;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            
            if(i==0 and j==0) {
                continue;
            }
            if(arr[i][j]==1) {
                continue;
            }
            
            
            if(arr[i][j+1]==0) {
                visited[i][j+1][0]=visited[i][j][0]+visited[i][j][1];
            }
            
            if(arr[i+1][j]==0) {
                visited[i+1][j][2]=visited[i][j][2]+visited[i][j][1];
            }
            
            if(i+1<N and j+1<N) {
                
                if(arr[i+1][j]==0 and arr[i][j+1]==0 and arr[i+1][j+1]==0) {
                    visited[i+1][j+1][1]=visited[i][j][1]+visited[i][j][0]+visited[i][j][2];
                }
            }
        }
    }
    
    cout << visited[N-1][N-1][0]+visited[N-1][N-1][1]+visited[N-1][N-1][2] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }
    
    go_();
    
    return 0;
}

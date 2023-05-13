#include <iostream>
using namespace std;

int visited[101][101];
char temp[101][101];


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int i,j;
    int H,W;
    cin >> H >> W;
    
    for(i=0;i<101;i++) {
        for(j=0;j<101;j++) {
            visited[i][j]=-1;
        }
    }
    
    for(i=1;i<=H;i++) {
        for(j=1;j<=W;j++) {
            cin >> temp[i][j];
        }
    }
    
    for(i=1;i<=H;i++) {
        for(j=1;j<=W;j++) {
            if(temp[i][j]=='c') {
                visited[i][j]=0;
            }
            else {
                if(visited[i][j-1]!=-1) {
                    visited[i][j]=visited[i][j-1]+1;
                }
            }
        }
    }
    
    
    for(i=1;i<=H;i++) {
        for(j=1;j<=W;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    
    
    
    return 0;
    
}

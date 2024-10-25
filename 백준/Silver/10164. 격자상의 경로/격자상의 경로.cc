#include <iostream>
#include <cstring>

using namespace std;

int N,M,K;
int visited[20][20];
int tempX,tempY;

void init_() {
    
    int curr_Cnt=1;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(curr_Cnt==K) {
                tempX=i;
                tempY=j;
            }
            curr_Cnt+=1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> K;
    init_();
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(i==1 and j==1) visited[i][j]=1;
            else visited[i][j]=visited[i-1][j]+visited[i][j-1];
        }
    }
    
    int ret;
    if(K==0) {
        ret=visited[N][M];
    } else {
        ret=visited[tempX][tempY];
        memset(visited,0,sizeof(visited));
        for(int i=tempX;i<=N;i++) {
            for(int j=tempY;j<=M;j++) {
                if(i==tempX and j==tempY) visited[i][j]=1;
                else visited[i][j]=visited[i-1][j]+visited[i][j-1];
            }
        }
        ret*=visited[N][M];
    }
    
    cout << ret << "\n";
    
    return 0;
}

#include <iostream>

using namespace std;

int N,M;
int visited[34][34];

void init_() {
    visited[1][1]=1;
    visited[2][1]=1;
    visited[2][2]=1;
    
    for(int i=3;i<=30;i++) {
        visited[i][1]=1;
        for(int j=2;j<i;j++) {
            visited[i][j]=visited[i-1][j-1]+visited[i-1][j];
        }
        visited[i][i]=1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    init_();
    cout << visited[N][M] << "\n";
    
    return 0;
}
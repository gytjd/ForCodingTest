#include <iostream>

using namespace std;

int N;
int visited[100004][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    visited[1][0]=1;
    visited[1][1]=1;
    visited[1][2]=1;
    
    for(int i=2;i<=N;i++) {
        visited[i][0]=(visited[i-1][0]+visited[i-1][1]+visited[i-1][2])%9901;
        visited[i][1]=(visited[i-1][0]+visited[i-1][2])%9901;
        visited[i][2]=(visited[i-1][0]+visited[i-1][1])%9901;
    }
    cout << (visited[N][0]+visited[N][1]+visited[N][2])%9901 << "\n";
    
    return 0;
}

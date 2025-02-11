#include <iostream>
#define MOD 10007
using namespace std;

int N;
int visited[1004][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<10;i++) {
        visited[1][i]=1;
    }
    
    for(int i=2;i<=N;i++) {
        visited[i][0]=1;
        for(int j=1;j<10;j++) {
            visited[i][j]=(visited[i-1][j]+visited[i][j-1])%MOD;
        }
    }
    
    int ret=0;
    for(int i=0;i<10;i++) {
        ret+=visited[N][i];
    }
    cout << ret%MOD << "\n";
    
    return 0;
}

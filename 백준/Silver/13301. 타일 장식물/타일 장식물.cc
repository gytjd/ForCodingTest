#include <iostream>

using namespace std;

int N;
long long visited[84];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    visited[1]=1;
    visited[2]=1;
    
    for(int i=3;i<=N;i++) {
        visited[i]=visited[i-2]+visited[i-1];
    }
    
    cout << visited[N]*2+(visited[N]+visited[N-1])*2 << "\n";
    
    return 0;
}

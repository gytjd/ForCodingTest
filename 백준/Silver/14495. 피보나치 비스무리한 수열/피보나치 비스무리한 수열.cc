#include <iostream>

using namespace std;

long long N;
long long visited[120];

void init_() {
    visited[1]=1;
    visited[2]=1;
    visited[3]=1;
    
    for(long long i=4;i<120;i++) {
        visited[i]=visited[i-1]+visited[i-3];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    init_();
    cout << visited[N] << "\n";
    
    return 0;
    
}

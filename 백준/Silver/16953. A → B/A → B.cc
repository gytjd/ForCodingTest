#include <iostream>
using namespace std;

long long N,M;
long long ret;

void go_(long long N,long long M,long long depth) {
    
    if(N==M) {
        ret=depth+1;
        return;
    }
    
    if(N*2<=M) {
        go_(N*2, M,depth+1);
    }
    
    if(N*10+1<=M) {
        go_(N*10+1, M,depth+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    go_(N, M,0);
    
    if(ret==0) {
        cout << -1 << "\n";
    }
    else {
        cout << ret << "\n";
    }
    
    return 0;
}

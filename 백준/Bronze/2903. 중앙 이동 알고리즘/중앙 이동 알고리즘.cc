#include <iostream>
using namespace std;

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    int tmp=1;
    int ret=1;
    
    for(int i=0;i<N;i++) {
        ret=tmp*2+1;
        tmp*=2;
    }
    
    cout << ret*ret << "\n";
    
    return 0;
}

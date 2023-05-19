#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int max_N=0;
    int ret=0;
    
    for(int i=0;i<4;i++) {
        int start,end;
        cin >> start >> end;
        ret=(ret-start)+end;
        max_N=max(max_N,ret);
    }
    
    cout << max_N << "\n";
    
    return 0;
}

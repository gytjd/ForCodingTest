#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int ret_sum=0;
    int ret=0;
    for(int i=0;i<10;i++) {
        int start,end;
        cin >> start >> end;
        
        ret_sum-=start;
        ret_sum+=end;
        
        ret=max(ret,ret_sum);
    }
    cout << ret << "\n";
    
    return 0;
}

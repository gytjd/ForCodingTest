#include <iostream>
using namespace std;

int X;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> X;
    
    int cnt_N=0;
    for(int i=0;i<7;i++) {
        
        if(X&(1<<i)) {
            cnt_N+=1;
        }
    }
    
    cout << cnt_N << "\n";
    
    return 0;
}

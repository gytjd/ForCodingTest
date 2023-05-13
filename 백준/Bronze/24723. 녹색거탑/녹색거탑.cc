#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int A;
    cin >> A;
    
    int ret=1;
    for(int i=1;i<=A;i++) {
        ret*=2;
    }
    
    cout << ret << "\n";
    
    return 0;
}

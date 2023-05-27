#include <iostream>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    long long sum=0;
    for(int i=1;i<N;i++) {
        sum+=i;
    }
    
    cout << sum << "\n";
    cout << 2 << "\n";
    
    return 0;
}

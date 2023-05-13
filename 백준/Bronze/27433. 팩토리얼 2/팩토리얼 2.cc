#include <iostream>
using namespace std;

long long N;

long long fac_(long long n) {
    if(n<=1) {
        return 1;
    }
    else {
        return n*fac_(n-1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    cout << fac_(N) << "\n";
    
    return 0;
}

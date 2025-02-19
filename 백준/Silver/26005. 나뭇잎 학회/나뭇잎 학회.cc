#include <iostream>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    if(N!=1) {
        if(N%2==0) {
            cout << (N*N)/2 << "\n";
        } else {
            cout << (N*N)/2+1 << "\n";
        }
    } else {
        cout << 0 << '\n';
    }
    
    return 0;
}

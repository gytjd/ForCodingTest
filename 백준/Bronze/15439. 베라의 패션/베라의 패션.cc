#include <iostream>

using namespace std;

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    cout << N*(N-1) << "\n";
    
    return 0;
}

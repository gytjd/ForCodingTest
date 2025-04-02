#include <iostream>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    cout << ((N%2)?"SK":"CY") << "\n";
    
    return 0;
}

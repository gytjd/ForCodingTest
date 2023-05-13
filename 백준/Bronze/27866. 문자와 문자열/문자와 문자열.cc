#include <iostream>

using namespace std;
string a;
int idx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> a;
    cin >> idx;
    cout << a[idx-1] << "\n";
    
    return 0;
    
}

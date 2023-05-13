#include <iostream>
using namespace std;
int n, i;
int main() {
    
    cin >> n;
    
    while (i * i <= n) {
        i++;
    }
    cout << i - 1 << "\n";
}

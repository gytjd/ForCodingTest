#include <iostream>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int i;
    for (i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        cout << a+b << "\n";
        
    }
    
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int i;
    int n,m;
    
    cin >> n >> m;
    
    int *p = new int[n];
    
    for(i=0;i<n;i++) {
        cin >> p[i];
    }
    
    for(i=0;i<n;i++) {
        if(p[i] < m) {
            cout << p[i] << " ";
        }
    }
    cout << endl;
    
    delete[] p;
    
    return 0;
}

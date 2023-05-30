#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a+b==c) {
        cout << a<<"+"<<b<<"="<<c << "\n";
    }
    if(a-b==c) {
        cout << a<<"-"<<b<<"="<<c << "\n";
    }
    if(a*b==c) {
        cout << a<<"*"<<b<<"="<<c << "\n";
    }
    if(a/b==c) {
        cout << a<<"/"<<b<<"="<<c << "\n";
    }
    
    if(a==b+c) {
        cout << a<<"="<<b<<"+"<<c<<"\n";
    }
    if(a==b-c) {
        cout << a<<"="<<b<<"-"<<c<<"\n";
    }
    if(a==b*c) {
        cout << a<<"="<<b<<"*"<<c<<"\n";
    }
    if(a==b/c) {
        cout << a<<"="<<b<<"/"<<c<<"\n";
    }
    
    return 0;
}

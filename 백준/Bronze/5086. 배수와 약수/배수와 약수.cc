#include <iostream>
using namespace std;

void is_(int a,int b) {
    
    if(b%a==0) {
        cout << "factor" << "\n";
    }
    else if(a%b==0) {
        cout << "multiple" << "\n";
    }
    else {
        cout << "neither" << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(1) {
        int a,b;
        cin >> a >> b;
        
        if(a==0 and b==0) {
            break;
        }
        
        is_(a, b);
    }
    
    return 0;
}

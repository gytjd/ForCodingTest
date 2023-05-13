#include <iostream>
#include <string>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string a;
    cin >> a;
    
    bool Flag=false;
    int temp=a.size()-1;
    for(int i=0;i<a.size()/2;i++) {
        if(a[i]!=a[temp-i]) {
            Flag=true;
            break;
        }
    }
    
    if(Flag) {
        cout << 0 << "\n";
    }
    else {
        cout << 1 << "\n";
    }
    
    return 0;
}

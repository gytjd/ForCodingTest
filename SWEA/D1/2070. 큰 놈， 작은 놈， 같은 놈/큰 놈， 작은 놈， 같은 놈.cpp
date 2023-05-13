#include <iostream>

using namespace std;

char is_equal(int a,int b){
    if(a>b){
        return '>';
    } else if(a<b) {
        return '<';
    } else {
        return '=';
    }
}
int main() {
    
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        
        cout << "#" << i+1 << " " << is_equal(a, b) << "\n";
    }
    
    return 0;
}

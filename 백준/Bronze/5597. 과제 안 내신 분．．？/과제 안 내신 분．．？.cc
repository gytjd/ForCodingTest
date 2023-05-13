#include <iostream>

using namespace std;

int main() {
    int *p=new int[30];
    int i;
    
    for(i=0;i<28;i++) {
        int a;
        cin >> a;
        p[a-1]=1;
    }
    
    
    for(i=0;i<30;i++) {
        if(p[i]==0) {
            cout << i+1 << "\n";
        }
    }
    
    delete[] p;
    
    return 0;
}

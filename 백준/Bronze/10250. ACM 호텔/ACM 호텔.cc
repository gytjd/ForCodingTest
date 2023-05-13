#include <iostream>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        int h,w,z;
        cin >> h >> w >> z;
        
        int temp = z/h;
        
        if(z%h!=0) {
            temp+=1;
        }
        
        if(h<z) {
            while(z>h) {
                z-=h;
            }
        }
        
        
        if(temp<10) {
            cout << z << "0" << temp << "\n";
        }
        else {
            cout << z << temp << "\n";
        }
    
    }
    
    return 0;
}

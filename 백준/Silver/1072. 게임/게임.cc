#include <iostream>

using namespace std;

double lowX,lowY,temp,init_X;
double highX=10000000000,highY;

int Z,temp_Z,ret,mid;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> lowX >> lowY;
    Z=(lowY*100)/lowX;
    temp=(lowX-lowY);
    init_X=lowX;
    
//    cout << Z << "\n";
    
    if(Z>=99) {
        cout << -1 << "\n";
        return 0;
    }
    else {
        
        while(lowX<=highX) {
            mid=(lowX+highX)/2;
            highY=mid-temp;
            
//            cout << mid << " " << highY << " " << temp << "\n";
            
            temp_Z=(highY*100)/mid;
//            cout << temp_Z << "\n";
            
            if(Z!=temp_Z) {
                ret=mid-init_X;
                highX=mid-1;
            }
            else {
                lowX=mid+1;
            }
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}


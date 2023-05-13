#include <iostream>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    
    for(int i=-999;i<=999;i++) {
        for(int j=-999;j<=999;j++) {
                    
            int tempA=a*i+b*j;
            int tempB=d*i+e*j;
            
            if(tempA==c and tempB==f) {
                cout << i << " " << j << "\n";
                break;
            }
        }
    }
    
    return 0;
}

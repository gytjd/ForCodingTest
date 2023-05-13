#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    int x1=98764321; int y1=987654321;
    int x2=-98765321; int y2=-98765321;
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int start,end;
        
        cin >> start >> end;
        
        if(x1>start) {
            x1=start;
        }
        
        if(x2<start) {
            x2=start;
        }
        
        
        if(y1>end) {
            y1=end;
        }
        
        if(y2<end) {
            y2=end;
        }
    }
    
    cout << abs(x1-x2)*abs(y1-y2) << "\n";
    return 0;
}

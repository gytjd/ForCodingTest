#include <iostream>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int a,b;
        cin >> a >> b;
        
        long long ret=1;
        
        int r=1;
        
        for(int j=b;j>b-a;j--) {
            ret*=j;
            ret/=r++;
        }
        
        cout << ret << "\n";
    }
    return 0;
}

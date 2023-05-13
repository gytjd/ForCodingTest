#include <iostream>
using namespace std;

int N,K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    
    int tot=0;
    int count_T=0;
    for(int i=1;i<=N;i++) {
        
        if(N%i==0) {
            if(count_T==K-1) {
                tot=i;
                break;
            }
            count_T+=1;
        }
    }
    
    cout << tot << "\n";
    
    
    return 0;
}

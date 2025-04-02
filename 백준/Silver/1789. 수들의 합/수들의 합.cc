#include <iostream>

using namespace std;

long long N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    long long cnt=0;
    long long temp=0;
    for(long long i=1;i<=N;i++) {
        temp+=i;
        
        if(temp>N) {
            break;
        }
        cnt+=1;
    }
    
    cout << cnt << "\n";
    
    return 0;
}

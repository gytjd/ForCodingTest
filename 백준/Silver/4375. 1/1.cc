#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N;
    
    while(cin >> N) {
    
        long long temp=1;
        int count=1;
        
        while(1) {
            
            if(temp%N==0) {
                cout << count << "\n";
                break;
            }
            count+=1;
            temp=(temp*10)%N+1%N;
        }
    }
    
    return 0;
}

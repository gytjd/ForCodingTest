#include <iostream>
#include <algorithm>
using namespace std;

long long ret;
long long N,K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    cin >> K;
    
    long long low,high;
    low=1;
    high=N*N;
    
    while(low<=high) {
        long long mid=(low+high)/2;
        long long temp=0;
        for(long long i=1;i<=N;i++) {
            temp+=min(N,mid/i);
        }
        
        if(temp<K) {
            low=mid+1;
        }
        else {
            ret=mid;
            high=mid-1;
        }
    }
    cout << ret << "\n";
    
    return 0;
    
}

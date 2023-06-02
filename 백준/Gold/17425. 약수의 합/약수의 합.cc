#include <iostream>
#include <cmath>

using namespace std;

int T,N;
long long dp[1000004];

void go_() {
    
    for(int i=1;i<=1000004;i++) {
        for(int j=i;j<=1000004;j+=i) {
            dp[j]+=i;
        }
    }
    
    for(int i=2;i<=1000004;i++) {
        dp[i]+=dp[i-1];
    }
}


int main() {
    
    go_();
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++) {
        scanf("%d",&N);
        printf("%lld\n",dp[N]);
    }
    
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[100004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<=N;i++) {
        dp[i]=987654321;
    }
    
    dp[2]=1;
    dp[4]=2;
    dp[5]=1;
    
    for(int i=6;i<=N;i++) {
        dp[i]=min(dp[i-2],dp[i-5])+1;
    }
    
    if(dp[N]!=987654321) {
        cout << dp[N] << "\n";
    }
    else {
        cout << -1 << "\n";
    }
    
    
    return 0;
    
}

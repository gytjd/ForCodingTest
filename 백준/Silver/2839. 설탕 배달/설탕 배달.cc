#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[5004];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<=N;i++) {
        dp[i]=-1;
    }
    dp[3]=1;
    dp[5]=1;
    
    for(int i=6;i<=N;i++) {
        if(dp[i-3]==-1 and dp[i-5]==-1) {
            dp[i]=-1;
        } else if(dp[i-3]!=-1 and dp[i-5]==-1) {
            dp[i]=dp[i-3]+1;
        } else if(dp[i-3]==-1 and dp[i-5]!=-1) {
            dp[i]=dp[i-5]+1;
        } else {
            dp[i]=min(dp[i-3],dp[i-5])+1;
        }
    }
    
    cout << dp[N] << "\n";
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int N,ret;
int arr[1004];
int dp[1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    ret=dp[0];
    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            if(arr[i]>arr[j]) {
                dp[i]=max(dp[j]+1,dp[i]);
                ret=max(dp[i],ret);
            }
        }
    }
    cout << ret+1 << "\n";

    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[10004];
int dp[10004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    dp[0]=arr[0];
    dp[1]=arr[0]+arr[1];
    dp[2]=max({dp[1],arr[0]+arr[2],arr[1]+arr[2]});
    
    for(int i=3;i<N;i++) {
        dp[i]=max({dp[i-1],dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i]});
    }
    cout << dp[N-1] << "\n";
    
    return 0;
}


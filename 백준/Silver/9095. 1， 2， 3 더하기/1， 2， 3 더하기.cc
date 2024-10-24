#include <iostream>

using namespace std;

int N;
int dp[14];

void init_() {
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    
    for(int i=4;i<=11;i++) {
        dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    init_();
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        cout << dp[data] << "\n";
    }
    
    return 0;
}

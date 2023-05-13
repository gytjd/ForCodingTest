#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int dp[24][104];
vector<int> hp;
vector<int> deli;

void go_() {
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=99;j++) {
            if(hp[i-1]>j) {
                dp[i][j]=dp[i-1][j];
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-hp[i-1]]+deli[i-1]);
            }
        }
    }
    
    cout << dp[N][99] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        hp.push_back(data);
    }
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        deli.push_back(data);
    }
    
    go_();
    
    return 0;
}

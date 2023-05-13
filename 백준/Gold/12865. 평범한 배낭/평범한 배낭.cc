#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,K;
int dp[104][100004];

vector<int> weight;
vector<int> value;

void display_() {
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=K;j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
void go_() {
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=K;j++) {
            
            if(weight[i-1]>j) {
                dp[i][j]=dp[i-1][j];
            }
            else {
                
                if(j-weight[i-1]>=0) {
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+value[i-1]);
                }
            }
        }
    }
    
    cout << dp[N][K] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    
    for(int i=0;i<N;i++) {
        int w,v;
        cin >> w >> v;
        weight.push_back(w);
        value.push_back(v);
    }
    
    go_();
//    display_();
    return 0;
}

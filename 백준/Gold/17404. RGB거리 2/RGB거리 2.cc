#include <iostream>
#include <algorithm>
#define INF 987654321;
using namespace std;

int N;
int arr[1004][3];
int dp[1004][3];
int ret=INF;

void init_() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<3;j++) {
            dp[i][j]=INF;
        }
    }
}
void go_(int idx) {
    
    init_();
    dp[0][idx]=arr[0][idx];
    
    for(int i=1;i<N;i++) {
        for(int j=0;j<3;j++) {
            if(j==0) {
                dp[i][j]=arr[i][j]+min(dp[i-1][1],dp[i-1][2]);
            }
            else if(j==1) {
                dp[i][j]=arr[i][j]+min(dp[i-1][0],dp[i-1][2]);
            }
            else {
                dp[i][j]=arr[i][j]+min(dp[i-1][0],dp[i-1][1]);
            }
        }
    }
    
    for(int i=0;i<3;i++) {
        if(i==idx) {
            continue;
        }
        
        ret=min(ret,dp[N-1][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<3;j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<3;i++) {
        go_(i);
    }
    
    cout << ret << "\n";
    
    return 0;
}

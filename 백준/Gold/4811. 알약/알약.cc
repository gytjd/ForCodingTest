#include <iostream>
using namespace std;

int N;
long long dp[34][34];


long long go_(int big,int small) {
    if(dp[big][small]) {
        return dp[big][small];
    }

    if(big==0 and small==0) {
        return 1;
    }
    
    if(small) {
        dp[big][small]+=go_(big, small-1);
    }
    
    if(big) {
        dp[big][small]+=go_(big-1, small+1);
    }
    return dp[big][small];
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(1) {
        long long data;
        cin >> data;
        
        if(data==0) {
            break;
        }
        
        cout << go_(data, 0) << "\n";
    }
    
    return 0;
    
}

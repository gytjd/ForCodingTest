#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int T,N,num;
int dp[10004];
vector<int> v;

void go_() {
    
    dp[0]=1;
    for(int i=1;i<=N;i++) {
        for(int j=v[i];j<=num;j++) {
            dp[j]+=dp[j-v[i]];
        }
    }
    
    cout << dp[num] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int i=0;i<T;i++) {
        v.clear();
        v.push_back(0);
        memset(dp, 0, sizeof(dp));
        cin >> N;
        for(int j=0;j<N;j++) {
            int data;
            cin >> data;
            v.push_back(data);
        }
        cin >> num;
        
        go_();
    }
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,ret=-987654321;
vector<pair<int, int>> v;
int dp[504];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int start,end;
        cin >> start >> end;
        v.push_back({start,end});
    }
    
    sort(v.begin(), v.end());
    
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<i;j++) {
            if(v[i].first>v[j].first and v[i].second>v[j].second) {
                dp[i]=max(dp[j]+1,dp[i]);
                ret=max(ret,dp[i]);
            }
        }
    }
    
    cout << N-(ret+1) << "\n";
    
    return 0;
}

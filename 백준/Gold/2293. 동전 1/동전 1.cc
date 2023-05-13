#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
int dp[100004];
vector<int> v;

void go_() {
    
    dp[0]=1;
    
    for(int a:v) {
        for(int i=a;i<=K;i++) {
            dp[i]+=dp[i-a];
        }
    }
    
    cout << dp[K] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    sort(v.begin(), v.end());
    
    go_();
    
    return 0;
}

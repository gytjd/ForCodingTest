#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n,c,P;
double m,p;
int dp[10005];

vector<int> cost;
vector<int> price;

void go_() {
    
    int temp=m*100;
    for(int i=0;i<n;i++) {
        for(int j=price[i];j<=temp;j++) {
            dp[j]=max(dp[j],dp[j-price[i]]+cost[i]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(1) {
        cost.clear();
        price.clear();
        memset(dp, 0, sizeof(dp));

        cin >> n >> m;
        if(n==0 and m==0.0) {
            break;
        }

        for(int i=0;i<n;i++) {
            
            cin >> c >> p;
            P=static_cast<int>(p*100.0+0.5);
            
            cost.push_back(c);
            price.push_back(P);
        }
        
        go_();
        cout << dp[int(m*100)] << "\n";
    }
    
    return 0;
}

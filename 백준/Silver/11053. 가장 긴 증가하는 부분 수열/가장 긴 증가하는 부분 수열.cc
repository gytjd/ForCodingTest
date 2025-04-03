#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    for(int i=0;i<N;i++) {
        
        if(dp.empty() or dp.back()<v[i]) {
            dp.push_back(v[i]);
        } else {
            int lb=lower_bound(dp.begin(), dp.end(), v[i])-dp.begin();
//            cout << i << " " << lb << "\n";
            dp[lb]=v[i];
        }
    }
    cout << dp.size() << "\n";
    
    return 0;
}

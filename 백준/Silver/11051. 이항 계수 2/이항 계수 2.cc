#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> K;
    
    vector<int> temp(K+1,0);
    vector<vector<int>> M(N+1,temp);
    
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=min(i,K);j++) {
            
            if(j==0 or i==j) {
                M[i][j]=1;
            }
            else {
                M[i][j]=(M[i-1][j-1]%10007+M[i-1][j]%10007)%10007;
            }
        }
    }
    
    cout << M[N][K] << "\n";
    
    return 0;
}

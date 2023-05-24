#include <iostream>
#include <cstring>
#define INF 987654321
using namespace std;

int N;
int arr[20][20];
int dp[20][1<<20];

int go_(int curr,int visited) {
    
    if(visited==(1<<N)-1) {
        if(arr[curr][0]==0) {
            return INF;
        }
        else {
            return arr[curr][0];
        }
    }
    
    if(dp[curr][visited]!=-1) {
        return dp[curr][visited];
    }
    dp[curr][visited]=INF;
    
    for(int i=0;i<N;i++) {
        
        if(visited & (1<<i)) {
            continue;
        }
        
        if(arr[curr][i]==0) {
            continue;
        }
        
        dp[curr][visited]=min(dp[curr][visited],go_(i, visited|(1<<i))+arr[curr][i]);
    }
    
    return dp[curr][visited];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    cout << go_(0,1) << "\n";
    
    return 0;
}

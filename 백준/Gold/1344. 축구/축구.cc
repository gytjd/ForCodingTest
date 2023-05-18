#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

double N,M;
double dp[20][20][20];
int visited[20];

void is_prime(int n) {
    
    visited[0]=1;
    visited[1]=1;
    
    for(int i=2;i<=n;i++) {
        
        if(visited[i]) {
            continue;
        }
        
        for(int j=2*i;j<=n;j+=i) {
            visited[j]=1;
        }
    }
}


double go_(int x,int y,int idx) {
    if(idx==18) {
        if(!visited[x] or !visited[y]) {
            return 1.0;
        }
        else {
            return 0.0;
        }
    }
    
    double &ret=dp[x][y][idx];
    
    if(ret>-0.5) {
        return ret;
    }
    
    ret=0.0;
    ret+=go_(x+1, y, idx+1)*N*(1-M);
    ret+=go_(x+1, y+1, idx+1)*N*M;
    ret+=go_(x, y+1, idx+1)*(1-N)*M;
    ret+=go_(x, y, idx+1)*(1-N)*(1-M);
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    memset(dp, -1, sizeof(dp));
    cin >> N;
    cin >> M;
    
    N/=100;
    M/=100;
    
    is_prime(20);
    printf("%.6f\n",go_(0, 0, 0));
    
    return 0;
}

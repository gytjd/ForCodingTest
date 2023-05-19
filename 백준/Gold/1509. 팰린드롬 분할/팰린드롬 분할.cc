#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 987654321

using namespace std;

long long N;
int dp[2504][2504];
int visited[2504];

vector<char> v;

void display_() {
    
    cout << "\n";
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

void start_() {
    visited[0]=0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=i;j++) {
            
            if(dp[j][i]) {
                visited[i]=min(visited[j-1]+1,visited[i]);
            }
        }
    }
    
    cout << visited[N] << "\n";
    
}

void go_() {
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=i;j++) {
            dp[i][j]=1;
        }
    }
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(j<=N and j+i<=N) {
                if(v[j]==v[j+i] and dp[j+1][j+i-1]==1) {
                    dp[j][j+i]=1;
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string a;
    cin >> a;
    N=a.size();
    
    v.push_back(' ');
    for(long long i=0;i<a.size();i++) {
        v.push_back(a[i]);
    }
    
    go_();
    
    fill(visited, visited+2504, INF);
    start_();
    
    return 0;
    
}


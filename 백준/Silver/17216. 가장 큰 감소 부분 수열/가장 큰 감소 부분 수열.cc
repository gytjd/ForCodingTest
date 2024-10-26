#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
int dp[1004];
int visited[1004];
int ret_Idx;

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
    
    dp[0]=1;
    visited[0]=v[0];
    int ret=visited[0];
    
    for(int i=1;i<N;i++) {
        int temp=0;
        int temp_visited=0;
        
        for(int j=0;j<i;j++) {
            if(v[j]>v[i]) {
                temp=max(temp,dp[j]);
                temp_visited=max(temp_visited,visited[j]);
            }
        }
        dp[i]=temp+1;
        visited[i]=temp_visited+v[i];
        ret=max(ret,visited[i]);
    }
    
    cout << ret << "\n";
    
    return 0;
}

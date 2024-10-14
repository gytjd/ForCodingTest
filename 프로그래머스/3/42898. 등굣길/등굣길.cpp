#include <string>
#include <vector>
#include <iostream>

using namespace std; 

int arr[104][104];
int visited[104][104];

int solution(int m, int n, vector<vector<int>> puddles) {
    
    for(vector<int> temp:puddles) {
        arr[temp[1]][temp[0]]=1;
    }
    
    visited[1][1]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j] or (i==1 and j==1)) continue;
            visited[i][j]=(visited[i-1][j]+visited[i][j-1])%1000000007;
        }
    }
    
    return visited[n][m]%1000000007;
}
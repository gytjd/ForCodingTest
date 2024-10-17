#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int ret;
int N;
vector<vector<int>> v;
int visited[10];

void DFS_recur(int curr,int k) {
    ret=max(ret,curr);
    if(curr==N) {
        return;
    }
    // cout << curr << "\n";
    
    for(int i=0;i<N;i++) {
        if(visited[i]==0 and k>=v[i][0]) {
            visited[i]=1;
            DFS_recur(curr+1,k-v[i][1]);
            visited[i]=0;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    N=dungeons.size();
    v=dungeons;
    
    DFS_recur(0,k);
    return ret;
}
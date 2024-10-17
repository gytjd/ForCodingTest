#include <string>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int arr[104][104];
int visited[104];

int BFS_iter(int start,int n) {
    
    int curr_Cnt=0;
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        curr_Cnt+=1;
        
        for(int i=1;i<=n;i++) {
            if(arr[start][i] and visited[i]==0) {
                visited[i]=1;
                q.push(i);
            }
        }
    }
    
    return curr_Cnt;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    
    for(vector<int> temp:wires) {
        arr[temp[0]][temp[1]]=1;
        arr[temp[1]][temp[0]]=1;
    }
    
    for(vector<int> temp:wires) {
        arr[temp[0]][temp[1]]=0;
        arr[temp[1]][temp[0]]=0;
        
        memset(visited,0,sizeof(visited));
        int temp_Num=BFS_iter(1,n);
        // cout << temp_Num << "\n";
        answer=min(answer,abs((temp_Num)-(n-temp_Num)));
        
        arr[temp[0]][temp[1]]=1;
        arr[temp[1]][temp[0]]=1;
    }
    return answer;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_SIZE 20004

using namespace std;

int N;
vector<int> arr[MAX_SIZE];
int visited[MAX_SIZE];
queue<int> q;

int BFS_iter() {
    
    int start;
    int temp_Ret=0;
    queue<int> p;
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        
        for(int temp:arr[start]) {
            if(visited[temp]==0) {
                visited[temp]=1;
                p.push(temp);
                temp_Ret+=1;
            }
        }
    }
    q=p;
    
    return temp_Ret;
}

int go_() {
    
    int ret=0;
    q.push(1);
    visited[1]=1;
    
    while(true) {
        int temp_ret=0;
        temp_ret=BFS_iter();
        if(temp_ret==0) {
            return ret;
        }
        ret=temp_ret;
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(vector<int> v:edge) {
        arr[v[0]].push_back(v[1]);
        arr[v[1]].push_back(v[0]);
    }
    answer=go_();
    return answer;
}
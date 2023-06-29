#include <iostream>
#include <vector>
using namespace std;

int N,M;
int S,E;
int ret=987654321;
vector<int> arr[104];
int visited[104];

void go_(int start,int depth) {
    
    visited[start]=1;
    
    if(start==E) {
        ret=depth;
        return;
    }
    
    for(int i=0;i<arr[start].size();i++) {
        if(visited[arr[start][i]]==0) {
            go_(arr[start][i], depth+1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    cin >> S >> E;
    cin >> M;
    
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        
        arr[start].push_back(end);
        arr[end].push_back(start);
    }
    
    go_(S, 0);
    
    if(ret==987654321) {
        cout << -1 << "\n";
    }
    else {
        cout << ret << "\n";
    }
    
    return 0;
}

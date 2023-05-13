#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree[50];
int visited[50];

void BFS_Tree(int start) {
    
    int tempq;
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    while(!q.empty()) {
        tempq=q.front();q.pop();
        
        for(int i=0;i<tree[tempq].size();i++) {
            visited[tree[tempq][i]]=1;
            q.push(tree[tempq][i]);
        }
    }
}

int size_(int idx) {
    int count=0;
    for(int i=0;i<tree[idx].size();i++) {
        
        if(visited[tree[idx][i]]!=1) {
            count +=1;
        }
    }
    
    return count;
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int temp;
        cin >> temp;
        
        if(temp==-1) {
            continue;
        }
        else {
            tree[temp].push_back(i);
        }
    }
    
    int count=0;
    int del_numl;
    cin >> del_numl;
    BFS_Tree(del_numl);
    

    for(int i=0;i<N;i++) {
        if(size_(i)==0 and visited[i]==0) {
            count+=1;
        }
    }

    
    cout << count << "\n";
    return 0;
}

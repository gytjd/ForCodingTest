#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int visited[1000004];
int dir[1000004];
vector<int> ret;

void BFS_iter(int start) {
    
    visited[start]=0;
    dir[start]=start;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        start=q.front();
        q.pop();
        
//        cout << start << "\n";
        
        if(start%3==0 and visited[start/3]==0 and start/3>=1)
        {
            q.push(start/3);
            visited[start/3]=visited[start]+1;
            dir[start/3]=start;
        }
        if(start%2==0 and visited[start/2]==0 and start/2>=1)
        {
            q.push(start/2);
            visited[start/2]=visited[start]+1;
            dir[start/2]=start;
        }
        
        if(visited[start-1]==0 and start-1>=1) {
            q.push(start-1);
            visited[start-1]=visited[start]+1;
            dir[start-1]=start;
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int start,temp;
    cin >> start;
    
    BFS_iter(start);
    cout << visited[1] << "\n";
    
    temp=dir[1];
    
    if(temp==1) {
        cout << 1 << "\n";
    }
    else {
        ret.push_back(1);
        
        while(temp!=start) {
            ret.push_back(temp);
            temp=dir[temp];
        }
        ret.push_back(start);
        
        reverse(ret.begin(), ret.end());
        
        for(int a:ret) {
            cout << a << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

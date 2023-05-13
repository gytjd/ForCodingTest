#include <iostream>
#include <vector>
using namespace std;

int q;
int N,M;

int visited[1004];
vector<int> arr[1004];

void init_() {
    for(int i=0;i<1004;i++) {
        visited[i]=0;
        arr[i].clear();
    }
}

void DFS_recur(int start) {
    visited[start]=1;
    
    for(int tmp:arr[start]) {
        if(visited[tmp]==0) {
            DFS_recur(tmp);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> q;
    
    for(int w=0;w<q;w++) {
        
        cin >> N;
        cin >> M;
        
        init_();
        
        for(int i=0;i<M;i++) {
            int start,end;
            cin >> start >> end;
            
            arr[start].push_back(end);
            arr[end].push_back(start);
        }
        
        if(N==M+1) {
            DFS_recur(1);
            bool check_Flag=false;
            
            for(int j=1;j<=N;j++) {
                if(visited[j]==0) {
                    check_Flag=true;
                    break;
                }
            }
            
            if(check_Flag) {
                cout << "graph" << "\n";
            }
            else {
                cout << "tree" << "\n";
            }
            
        }
        else {
            cout << "graph" << "\n";
        }
    }
    
    return 0;
}

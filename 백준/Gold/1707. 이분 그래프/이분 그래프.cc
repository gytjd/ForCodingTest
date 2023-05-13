#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> temp[20001];
int visited[200001];
int V,E;

void init_fun() {
    int i;
    for(i=0;i<20001;i++) {
        temp[i].clear();
        visited[i]=0;
    }
}

void BFS_tree(int start) {
    
    if(visited[start]==0) {
        visited[start]=1;
    }
    
    int i;
    int w;
    queue<int> q;
    
    q.push(start);
    
    while(!q.empty()) {
        w=q.front();q.pop();
        
        for(int tempR:temp[w]) {
            
            if(visited[tempR]==0) {
                
                if(visited[w]==1) {
                    visited[tempR]=2;
                }
                else if(visited[w]==2) {
                    visited[tempR]=1;
                }
                q.push(tempR);
            }
        }
    }
}

int color_check() {
    
    int i,j;
    for(i=1;i<=V;i++) {
        int curr_Cor=visited[i];
        
        for(int temp_Cor:temp[i]) {
            
            if(curr_Cor==visited[temp_Cor]) {
                return -1;
            }
        }
        
    }
    
    return 1;
}


int main() {
    
    int q;
    int tc;
    cin >> tc;
    
    for(q=0;q<tc;q++) {
        
        int i;
        cin >> V >> E;
        
        init_fun();
        
        for(i=0;i<E;i++) {
            int E1,E2;
            cin >> E1 >> E2;
            
            temp[E1].emplace_back(E2);
            temp[E2].emplace_back(E1);
        }
        
        for(i=1;i<=V;i++) {
            if(visited[i]==0) {
                BFS_tree(i);
            }
        }
        
        int result=color_check();
        
        if(result==-1) {
            cout << "NO" << "\n";
        }
        else {
            cout << "YES" << "\n";
        }
    }
    
    return 0;
}

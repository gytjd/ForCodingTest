#include <iostream>
#include <queue>

using namespace std;

int V,E;
vector<int> arr[32004];
int in_degree[32004];
vector<int> ret;

void topo_() {
    
    queue<int> q;
    for(int i=1;i<=V;i++) {
        if(in_degree[i]==0) {
            q.push(i);
        }
    }
    
    int start=0;
    while(!q.empty()) {
        start=q.front();
        q.pop();
        ret.push_back(start);
        
        for(int temp:arr[start]) {
            in_degree[temp]-=1;
            if(in_degree[temp]==0) {
                q.push(temp);
            }
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> V >> E;
    
    for(int i=0;i<E;i++) {
        int start,end;
        cin >> start >> end;
        arr[start].push_back(end);
        in_degree[end]+=1;
    }
    
    topo_();
    for(int temp:ret) {
        cout << temp << " ";
    }
    cout << "\n";
    
    return 0;
}

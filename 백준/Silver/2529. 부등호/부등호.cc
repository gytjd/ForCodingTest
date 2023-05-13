#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
int visited[10];
int ret[10];

bool first_Flag=false;
int first[10];
int fin[10];

void DFS_recur(int start,int end,int depth) {
    
    if(depth==N+1) {
        
        if(first_Flag==false) {
            for(int i=0;i<N+1;i++) {
                first[i]=ret[i];
            }
            first_Flag=true;
        }
        
        for(int i=0;i<N+1;i++) {
            fin[i]=ret[i];
        }
        return;
    }
    
    for(int i=start;i<end;i++) {
        
        if(visited[i]==0) {
            visited[i]=1;
            ret[depth]=i;
            
            if(v[depth]=='<') {
                DFS_recur(i+1, 10, depth+1);
            }
            else {
                DFS_recur(0, i, depth+1);
            }
            
            visited[i]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        char data;
        cin >> data;
        v.push_back(data);
    }
    
    DFS_recur(0, 10, 0);
    
    for(int i=0;i<N+1;i++) {
        cout << fin[i];
    }
    cout << "\n";

    for(int i=0;i<N+1;i++) {
        cout << first[i];
    }
    cout << "\n";
    
    
    return 0;
}

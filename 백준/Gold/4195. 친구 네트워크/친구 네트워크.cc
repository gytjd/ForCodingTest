#include <iostream>
#include <map>
#include <cstring>

#define MAX_SIZE 200004

using namespace std;

int N,M;
map<string, int> q;

int visited[MAX_SIZE];
long long ret[MAX_SIZE];

void init_() {
    for(int i=0;i<MAX_SIZE;i++) {
        visited[i]=-1;
        ret[i]=1;
    }
}

int find_root(int a) {
    
    if(visited[a]==-1) {
        return a;
    }
    return find_root(visited[a]);
}

void union_(int a,int b) {
    int root1=find_root(a);
    int root2=find_root(b);
    
    if(root1!=root2) {
        
        ret[root2]+=ret[root1];
        visited[root1]=root2;
    }
    
    cout << ret[root2] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    int temp;
    for(int i=0;i<N;i++) {
        cin >> M;
        temp=1;
        q.clear();
        init_();
        
        for(int j=0;j<M;j++) {
            string a,b;
            cin >> a >> b;
            
            if(q[a]==0) {
                q[a]=temp++;
            }
            if(q[b]==0) {
                q[b]=temp++;
            }
            
            union_(q[a], q[b]);
        }
    }
    return 0;
}



#include <iostream>
#include <vector>

using namespace std;

int N,M;
int ret;
int parent[500004];
vector<pair<int,int>> v;

void init_Parent() {
    for(int i=0;i<N;i++) {
        parent[i]=-1;
    }
}

int find_Parent(int curr) {
    
    if(parent[curr]==-1) {
        return curr;
    }
    parent[curr]=find_Parent(parent[curr]);
    return parent[curr];
}

void union_Parent(int a,int b) {
    int root1=find_Parent(a);
    int root2=find_Parent(b);
    
    if(root1!=root2) {
        parent[root1]=root2;
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    init_Parent();

    for(int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    
    for(int i=0;i<M;i++) {
        int uset=find_Parent(v[i].first);
        int vset=find_Parent(v[i].second);
        
        if(uset!=vset) {
            union_Parent(uset, vset);
        } else {
            ret=i+1;
            break;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}

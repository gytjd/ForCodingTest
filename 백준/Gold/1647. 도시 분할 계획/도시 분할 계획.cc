#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int start,end,weight;
};

struct cmp {
    bool operator()(Node &a,Node &b) {
        return a.weight>b.weight;
    }
};

priority_queue<Node,vector<Node>,cmp> q;

int N,M;
int parent[100004];

int set_root(int a) {
    
    if(parent[a]==-1) {
        return a;
    }
    
    parent[a]=set_root(parent[a]);
    
    return set_root(parent[a]);
}

void se_union(int a,int b) {
    int root1=set_root(a);
    int root2=set_root(b);
    
    if(root1!=root2) {
        parent[root1]=root2;
    }
}

void Kruskal_() {
    
    memset(parent, -1, sizeof(parent));
    
    int ret=0;
    int uset,vset;
    int edge_accepted=0;
    
    while(edge_accepted<N-2) {
        Node temp=q.top();
        
        uset=set_root(temp.start);
        vset=set_root(temp.end);
        q.pop();
        
        if(uset!=vset) {
            edge_accepted+=1;
            se_union(uset, vset);
            ret+=temp.weight;
        }
    }
    
    cout << ret << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int start,end,weight;
        cin >> start >> end >> weight;
        q.push({start,end,weight});
    }

    Kruskal_();
    
    return 0;
}

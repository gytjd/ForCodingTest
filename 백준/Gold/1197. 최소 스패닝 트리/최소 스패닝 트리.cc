#include <iostream>
#include <queue>

using namespace std;

int V,E;

struct Node {
    int start,end,weight;
};

struct cmp {
    bool operator() (Node a,Node b) {
        return a.weight>b.weight;
    }
};

int parent[10004];
priority_queue<Node,vector<Node>,cmp> q;

void init_set() {
    for(int i=0;i<10004;i++) {
        parent[i]=-1;
    }
}

int find_set(int curr) {
    if(parent[curr]==-1) {
        return curr;
    }
    
    parent[curr]=find_set(parent[curr]);
    
    return find_set(parent[curr]);
}

void union_set(int a,int b) {
    int root1=find_set(a);
    int root2=find_set(b);
    
    if(root1!=root2) {
        parent[root1]=root2;
    }
}

void Kruskal() {
    
    int cnt_T=0;
    init_set();
    Node e;
    int uset,vset;
    int edge_accepted=0;
    
    while(edge_accepted!=V-1) {
        e=q.top();
        q.pop();
        
        uset=find_set(e.start);
        vset=find_set(e.end);
        
        if(uset!=vset) {
            union_set(uset, vset);
            edge_accepted+=1;
            cnt_T+=e.weight;
        }
    }
    
    cout << cnt_T << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> V >> E;
    
    for(int i=0;i<E;i++) {
        int start,end,weight;
        cin >> start >> end >> weight;
        q.push({start,end,weight});
    }
    
    Kruskal();
    
    return 0;
}

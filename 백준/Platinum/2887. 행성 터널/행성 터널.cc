#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int start,end,weight;
};

struct cmp {
    bool operator()(Node &a,Node &b) {
        return a.weight>b.weight;
    }
};

int N;
vector<pair<int, int>> v[3];
priority_queue<Node,vector<Node>,cmp> q;

int parent[100004];

void init_() {
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    sort(v[2].begin(), v[2].end());
    
    for(int i=0;i<N-1;i++) {
        q.push({v[0][i].second,v[0][i+1].second,abs(v[0][i].first-v[0][i+1].first)});
        q.push({v[1][i].second,v[1][i+1].second,abs(v[1][i].first-v[1][i+1].first)});
        q.push({v[2][i].second,v[2][i+1].second,abs(v[2][i].first-v[2][i+1].first)});
    }
}

void init_Parent() {
    for(int i=0;i<N;i++) {
        parent[i]=-1;
    }
}

int find_Set(int curr) {
    if(parent[curr]==-1) {
        return curr;
    }
    return parent[curr]=find_Set(parent[curr]);
}

void union_Set(int a,int b) {
    int rootA=find_Set(a);
    int rootB=find_Set(b);
    
    if(rootA!=rootB) {
        parent[rootA]=rootB;
    }
}

void Kruskal_() {
    
    long long ret=0;
    int u,v,w;
    int edge_accepted=0;
    
    while(edge_accepted!=N-1) {
        u=find_Set(q.top().start);
        v=find_Set(q.top().end);
        w=q.top().weight;
        q.pop();
        
        if(u!=v) {
            edge_accepted+=1;
            union_Set(u, v);
            ret+=w;
        }
    }
    
    cout << ret << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int A,B,C;
        cin >> A >> B >> C;
        v[0].push_back({A,i});
        v[1].push_back({B,i});
        v[2].push_back({C,i});
    }
    
    init_();
    init_Parent();
    Kruskal_();
    
    return 0;
}

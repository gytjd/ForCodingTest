#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x,y,idx;
};

struct cmp_B {
    bool operator()(Node &a,Node &b) {
        if(a.x==b.x) {
            return a.y<b.y;
        }
        return a.x<b.x;
    }
};

int ret;
int N,M,T;
int tree[400004];
vector<pair<int, int>> v;
vector<Node> q;

bool cmp_A(pair<int, int> &a,pair<int, int> &b) {
    
    if(a.second==b.second) {
        return a.first<b.first;
    }
    return a.second<b.second;
}


void update_(int node,int start,int end,int idx,int num) {
    
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]=num;
        return;
    }
    
    update_(node*2, start, (start+end)/2, idx, num);
    update_(node*2+1, (start+end)/2+1, end, idx, num);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

int max_Num(int node,int start,int end,int left,int right) {
    
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    int tempA=max_Num(node*2, start, (start+end)/2, left, right);
    int tempB=max_Num(node*2+1, (start+end)/2+1, end, left, right);
    return max(tempA,tempB);
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    cin >> T;
    for(int i=0;i<T;i++) {
        int s,e;
        cin >> s >> e;
        v.push_back({s,e});
    }
    sort(v.begin(), v.end(), cmp_A);
    
    for(int i=0;i<T;i++) {
        q.push_back({v[i].first,v[i].second,i});
    }
    sort(q.begin(), q.end(), cmp_B());
    
    for(Node temp:q) {
        
        if(temp.x>N or temp.y>M) {
            continue;
        }
        
        int tempIdx=max_Num(1, 0, T-1, 0, temp.idx-1);
        update_(1, 0, T-1, temp.idx, tempIdx+1);
        
        ret=max(ret,tempIdx+1);
    }
    
    cout << ret << "\n";
    
    return 0;
}

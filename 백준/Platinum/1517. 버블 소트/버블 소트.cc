#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N,H;
long long treeSize;
vector<pair<long long, int>> v;

long long query_(vector<long long> &tree,int node,int start,int end,int left,int right) {
    
//    cout << start << " " << end << "\n";
    
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    long long tempA=query_(tree, node*2, start, (start+end)/2, left, right);
    long long tempB=query_(tree, node*2+1, (start+end)/2+1, end, left, right);
    return tempA+tempB;
}

void update_(vector<long long> &tree,int node,int start,int end,int idx,long long temp) {
    
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]=temp;
        return;
    }
    
    update_(tree, node*2, start, (start+end)/2, idx, temp);
    update_(tree, node*2+1, (start+end)/2+1, end, idx, temp);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(long long i=0;i<N;i++) {
        long long data;
        cin >> data;
        v.push_back({data,i});
    }
    
    H=ceil(log2(N));
    treeSize=1<<(H+1);
    vector<long long> tree(treeSize);
    sort(v.begin(), v.end());
    
    long long ret=0;
    for(int i=0;i<N;i++) {
        ret+=query_(tree, 1, 0, N-1, v[i].second, N-1);
        update_(tree, 1, 0, N-1, v[i].second, 1);
    }
    
    cout << ret << "\n";
    return 0;
}

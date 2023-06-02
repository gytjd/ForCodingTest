#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define INF 1000000000

using namespace std;

int N,M,H;
long long treeSize;
vector<long long> v;

void display_(vector<long long> &tree) {
    for(int i=1;i<treeSize;i++) {
        cout << tree[i] << " ";
    }
    cout << "\n";
}

void init_(vector<long long> &tree,int node,int start,int end) {
    if(start==end) {
        tree[node]=v[start];
    }
    else {
        init_(tree, node*2, start, (start+end)/2);
        init_(tree, node*2+1, (start+end)/2+1, end);
        tree[node]=min(tree[node*2],tree[node*2+1]);
    }
}

long long sum_(vector<long long> &tree,int node,int start,int end,int left,int right) {
    
    if(left>end or right<start) {
        return INF;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    long long tempA=sum_(tree, node*2, start, (start+end)/2, left, right);
    long long tempB=sum_(tree,node*2+1,(start+end)/2+1,end,left,right);
    
    return min(tempA,tempB);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        long long data;
        cin >> data;
        v.push_back(data);
    }
    H=ceil(log2(N));
    treeSize=(1<<(H+1));
    vector<long long> tree(treeSize,INF);
    
    init_(tree, 1, 0, N-1);
//    display_(tree);
    
    for(int i=0;i<M;i++) {
        int left,right;
        cin >> left >> right;
        cout << sum_(tree, 1, 0, N-1, left-1, right-1) << "\n";
    }
    
    return 0;
}

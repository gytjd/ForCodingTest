#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N,M,H;
long long treeSize;

vector<long long> v;

void init_(vector<long long> &tree,int node,int start,int end) {
    if(start==end) {
        tree[node]=v[start];
    }
    else {
        init_(tree, node*2, start, (start+end)/2);
        init_(tree, node*2+1, (start+end)/2+1, end);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
}
long long sum_(vector<long long> &tree,int node,int start,int end,int left,int right) {
    
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    long long tempA=sum_(tree, node*2, start, (start+end)/2, left, right);
    long long tempB=sum_(tree, node*2+1, (start+end)/2+1, end, left, right);
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
    
    cin >> N >> M;
    H=ceil(log2(N));
    treeSize=(1<<(H+1));
    vector<long long> tree(treeSize);
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    init_(tree, 1, 0, N-1);
    
    for(int i=0;i<M;i++) {
        int a,b,c;
        long long d;
        
        cin >> a >> b >> c >> d;
        if(a>b) {
            int temp;
            temp=a;
            a=b;
            b=temp;
        }
        
        cout << sum_(tree, 1, 0, N-1, a-1, b-1) << "\n";
        v[c-1]=d;
        update_(tree, 1, 0, N-1, c-1, d);
    }
    
    return 0;
    
}


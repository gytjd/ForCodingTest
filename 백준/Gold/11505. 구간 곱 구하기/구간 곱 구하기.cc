#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N,M,K,H;
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
    } else {
        init_(tree, node*2, start, (start+end)/2);
        init_(tree,node*2+1,(start+end)/2+1,end);
        tree[node]=(tree[node*2]*tree[node*2+1])%1000000007;
    }
}

long long sum_(vector<long long> &tree,int node,int start,int end,int left,int right) {
    
//    cout << start << " " << end << "\n";
    
    if(left>end or right<start) {
        return 1;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    long long tempA=sum_(tree, node*2, start, (start+end)/2, left, right);
    long long tempB=sum_(tree,node*2+1,(start+end)/2+1,end,left,right);
//    cout << (tempA*tempB)%1000000007 << "\n";
    return (tempA*tempB)%1000000007;
}

void update_(vector<long long> &tree,int node,int start,int end,int idx,long long temp) {
    
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        v[start]=temp;
        tree[node]=temp;
        return;
    }
    
    if(start!=end) {
        update_(tree, node*2, start, (start+end)/2, idx, temp);
        update_(tree, node*2+1, (start+end)/2+1, end, idx, temp);
        tree[node]=(tree[node*2]*tree[node*2+1])%1000000007;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        long long data;
        cin >> data;
        v.push_back(data);
    }
    
    H=ceil(log2(N));
    treeSize=1<<(H+1);
    vector<long long> tree(treeSize);
    
    init_(tree, 1, 0, N-1);
//    display_(tree);
    M+=K;
    
    for(int i=0;i<M;i++) {
        int data;
        cin >> data;
        
        if(data==1) {
            int a;
            long long b;
            cin >> a >> b;
            update_(tree, 1, 0, N-1, a-1, b);
//            display_(tree);
        }
        else if(data==2) {
            int a,b;
            cin >> a >> b;
            cout << sum_(tree, 1, 0, N-1, a-1, b-1) << "\n";
        }
    }
    
    return 0;
}

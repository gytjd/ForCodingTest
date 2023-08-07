#include <iostream>
#define MAX_SIZE 1000004
using namespace std;

int N,M,K;
long long arr[MAX_SIZE];
long long tree[MAX_SIZE*4];
long long lazy[MAX_SIZE*4];

void init_(int node,int start,int end) {
    if(start==end) {
        tree[node]=arr[start];
        return;
    }
    
    init_(node*2, start,(start+end)/2);
    init_(node*2+1,(start+end)/2+1,end);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void update_Lazy(int node,int start,int end) {
    if(lazy[node]!=0) {
        tree[node]+=(end-start+1)*lazy[node];
        
        if(start!=end) {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
    }
    lazy[node]=0;
}

void update_Range(int node,int start,int end,long long left,long long right,long long num) {
    
    update_Lazy(node, start, end);
    
    if(left>end or right<start) {
        return;
    }
    
    
    if(left<=start and right>=end) {
        tree[node]+=(end-start+1)*num;
        
        if(start!=end) {
            lazy[node*2]+=num;
            lazy[node*2+1]+=num;
        }
        return;
    }
    
    update_Range(node*2, start, (start+end)/2, left, right, num);
    update_Range(node*2+1, (start+end)/2+1, end, left, right, num);
    tree[node]=tree[node*2]+tree[node*2+1];
}

long long sum_(int node,int start,int end,long long left,long long right) {
    update_Lazy(node, start, end);
    
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    long long tempA=sum_(node*2, start, (start+end)/2, left, right);
    long long tempB=sum_(node*2+1, (start+end)/2+1, end, left, right);
    return tempA+tempB;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    init_(1, 0, N-1);
    
    for(int i=0;i<M+K;i++) {
        long long A,B,C,D;
        cin >> A;
        
        if(A&1) {
            cin >> B >> C >> D;
            update_Range(1, 0, N-1, B-1, C-1, D);
        }
        else {
            cin >> B >> C;
            cout << sum_(1, 0, N-1, B-1, C-1) << "\n";
        }
    }
    
    return 0;
}

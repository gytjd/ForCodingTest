#include <iostream>
#define MAX_SIZE 100004
using namespace std;

int N,M;
int tree[MAX_SIZE*4];
int lazy[MAX_SIZE*4];

void update_lazy(int node,int start,int end) {
    if(lazy[node]%2==1) {
        tree[node]=(end-start+1)-tree[node];
        if(start!=end) {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void update_range(int node,int start,int end,int left,int right) {
    update_lazy(node, start, end);
    
    if(left>end or right<start) {
        return;
    }
    
    if(left<=start and right>=end) {
        tree[node]=(end-start+1)-tree[node];
        if(start!=end) {
            lazy[node*2]+=1;
            lazy[node*2+1]+=1;
        }
        return;
    }
    
    update_range(node*2, start, (start+end)/2, left, right);
    update_range(node*2+1, (start+end)/2+1, end, left, right);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int sum_(int node,int start,int end,int left,int right) {
    update_lazy(node, start, end);
    
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    int tempA=sum_(node*2, start, (start+end)/2, left, right);
    int tempB=sum_(node*2+1, (start+end)/2+1, end, left, right);
    return tempA+tempB;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<M;i++) {
        int A,B,C;
        cin >> A >> B >> C;
        
        if(A&1) {
            cout << sum_(1, 0, N-1, B-1, C-1) << "\n";
        }
        else {
            update_range(1, 0, N-1, B-1, C-1);
        }
    }
    
    return 0;
}

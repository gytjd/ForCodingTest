#include <iostream>
#define MAX_SIZE 500004

using namespace std;

int N,M;
int arr[MAX_SIZE];
int tree[MAX_SIZE*4];
int lazy[MAX_SIZE*4];

void init_(int node,int start,int end) {
    if(start==end) {
        tree[node]=arr[start];
        return;
    }
    
    init_(node*2, start, (start+end)/2);
    init_(node*2+1,(start+end)/2+1,end);
    tree[node]=tree[node*2]^tree[node*2+1];
}

void update_lazy(int node,int start,int end) {
    if(lazy[node]!=0) {
        tree[node]^=((end-start+1)%2)*lazy[node];
        
        if(start!=end) {
            lazy[node*2]^=lazy[node];
            lazy[node*2+1]^=lazy[node];
        }
        lazy[node]=0;
    }
}

void update_range(int node,int start,int end,int left,int right,int num) {
    update_lazy(node, start, end);
    
    if(left>end or right<start) {
        return;
    }
    
    if(left<=start and right>=end) {
        tree[node]^=((end-start+1)%2)*num;
        if(start!=end) {
            lazy[node*2]^=num;
            lazy[node*2+1]^=num;
        }
        return;
    }
    
    update_range(node*2, start, (start+end)/2, left, right, num);
    update_range(node*2+1, (start+end)/2+1, end, left, right, num);
    tree[node]=tree[node*2]^tree[node*2+1];
}

int query_(int node,int start,int end,int left,int right) {
    
    update_lazy(node, start, end);
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    int tempA=query_(node*2, start, (start+end)/2, left, right);
    int tempB=query_(node*2+1, (start+end)/2+1, end, left, right);
    return tempA^tempB;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    init_(1, 0, N-1);
    
    cin >> M;
    for(int i=0;i<M;i++) {
        int A,B,C,D;
        cin >> A;
        if(A&1) {
            cin >> B >> C >> D;
            update_range(1, 0, N-1, B, C, D);
        }
        else {
            cin >> B;
            cout << query_(1, 0, N-1, B, B) << "\n";
        }
    }
    
    return 0;
}

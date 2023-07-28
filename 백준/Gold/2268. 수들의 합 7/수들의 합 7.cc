#include <iostream>
using namespace std;

int N,M;
long long tree[4000004];

void update_(int node,int start,int end,long long idx,long long num) {
    
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]=num;
        return;
    }
    
    update_(node*2, start, (start+end)/2, idx, num);
    update_(node*2+1, (start+end)/2+1, end, idx, num);
    tree[node]=tree[node*2]+tree[node*2+1];
}

long long sum_(int node,int start,int end,long long left,long long right) {
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    long long tempA=sum_(node*2, start, (start+end)/2, left, right);
    long long tempB=sum_(node*2+1,(start+end)/2+1,end,left,right);
    return tempA+tempB;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        long long A,B,C;
        cin >> A >> B >> C;
        if(A&1) {
            update_(1, 0, N-1, B-1,C);
        }
        else {
            if(B<C) {
                cout << sum_(1, 0, N-1, B-1, C-1) << "\n";
            }
            else {
                cout << sum_(1,0,N-1,C-1,B-1) << "\n";
            }
        }
    }
    
    return 0;
}

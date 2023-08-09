#include <iostream>
#define MAX_SIZE 2000004
using namespace std;

int N;
int tree[MAX_SIZE*4];

void update_(int node,int start,int end,int idx,int num) {
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end){
        tree[node]+=num;
        return;
    }
    
    update_(node*2,start,(start+end)/2,idx,num);
    update_(node*2+1,(start+end)/2+1,end,idx,num);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int query_(int node,int start,int end,int num) {
    if(start==end) {
        return start;
    }
    
    if(tree[node*2]<num) { // 오른쪽
        return query_(node*2+1, (start+end)/2+1, end, num-tree[node*2]);
    }
    else {
        return query_(node*2, start, (start+end)/2, num);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int A,B;
        cin >> A >> B;
        if(A&1) {
            update_(1, 0, MAX_SIZE, B,1);
        }
        else {
            int temp=query_(1, 0, MAX_SIZE, B);
            update_(1, 0, MAX_SIZE, temp,-1);
            cout << temp << "\n";
        }
    }
    return 0;
}

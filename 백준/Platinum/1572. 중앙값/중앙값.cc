#include <iostream>
#define SIZE 250001

using namespace std;

int N,M;
int arr[SIZE];
int tree[SIZE*4];

void update_(int node,int start,int end,int idx,int value) {
    
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]+=value;
        return;
    }
    
    update_(node*2,start,(start+end)/2,idx,value);
    update_(node*2+1,(start+end)/2+1,end,idx,value);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int find_K(int node,int start,int end,int num) {
    
    if(start==end) {
        return start;
    }
    
    if(tree[node*2]>=num) {
        return find_K(node*2, start, (start+end)/2, num);
    }
    else {
        return find_K(node*2+1,(start+end)/2+1,end,num-tree[node*2]);
    }
}

void go_() {
    
    long long ret=0;
    for(int i=M-1;i<N;i++) {
        update_(1, 0, SIZE-1, arr[i], 1);
        ret+=find_K(1,0,SIZE-1,(M+1)/2);
        update_(1,0,SIZE-1,arr[i-M+1],-1);
    }
    
    cout << ret << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    for(int i=0;i<M-1;i++) {
        update_(1, 0,SIZE-1, arr[i], 1);
    }
    
    go_();
    
    return 0;
}

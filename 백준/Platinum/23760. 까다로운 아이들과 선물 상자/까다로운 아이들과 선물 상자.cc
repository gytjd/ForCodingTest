#include <iostream>
#define MAX_SIZE 100004

using namespace std;

int N,M;

int w[MAX_SIZE];
int b[MAX_SIZE];
int tree[MAX_SIZE*4];

void update_(int node,int start,int end,int idx,int num) {
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]+=num;
        return;
    }
    
    update_(node*2, start, (start+end)/2, idx, num);
    update_(node*2+1,(start+end)/2+1,end,idx,num);
    tree[node]=tree[node*2]+tree[node*2+1];
    
}

int num_(int node,int start,int end,int num) {

    
    if(start==end){
        return start;
    }
    
    if(tree[node*2+1]>=num) {
        return num_(node*2+1,(start+end)/2+1, end, num);
    }
    else {
        return num_(node*2,start,(start+end)/2, num-tree[node*2+1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        update_(1, 0, MAX_SIZE, data, 1);
    }
    
    for(int i=0;i<M;i++) {
        cin >> w[i];
    }
    for(int i=0;i<M;i++) {
        cin >> b[i];
    }
    for(int i=0;i<M;i++) {
        int idx=num_(1, 0, MAX_SIZE, b[i]);
        if(w[i]>idx) {
            cout << 0 << "\n";
            exit(0);
        }
        
        update_(1, 0, MAX_SIZE, idx, -1);
        update_(1, 0, MAX_SIZE, idx-w[i], 1);
    }
    
    cout << 1 << "\n";
    
    return 0;
}

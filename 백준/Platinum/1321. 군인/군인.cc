#include <iostream>
#include <vector>
using namespace std;

int N,M;
long long arr[500004];
long long tree[20000004];
vector<long long> ret;

void init_(int node,int start,int end) {
    if(start==end) {
        tree[node]=arr[start];
        return;
    }
    
    init_(node*2,start,(start+end)/2);
    init_(node*2+1,(start+end)/2+1,end);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void update_(int node,int start,int end,long long idx,long long num) {
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==idx and end==idx) {
        tree[node]+=num;
        return;
    }
    
    update_(node*2,start,(start+end)/2,idx,num);
    update_(node*2+1,(start+end)/2+1,end,idx,num);
    tree[node]=tree[node*2]+tree[node*2+1];
}

long long find_Mil(int node,int start,int end,long long num) {
    
    if(start==end) {
        return start+1;
    }
    
    if(tree[node*2]<num) {
        return find_Mil(node*2+1, (start+end)/2+1, end, num-tree[node*2]);
    }
    else {
        return find_Mil(node*2,start,(start+end)/2,num);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    cin >> M;
    init_(1, 0, N-1);
    
    for(int i=0;i<M;i++) {
        long long A,B,C;
        cin >> A;
        if(A&1) {
            cin >> B >> C;
            update_(1, 0, N-1, B-1, C);
        }
        else {
            cin >> B;
            ret.push_back(find_Mil(1, 0, N-1, B));
        }
    }
    
    for(long long temp:ret) {
        cout << temp << "\n";
    }
    
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[100004];
int tree[400004];
long long ret;

void init_(int node,int start,int end) {
    if(start==end){
        tree[node]=start;
        return;
    }
    
    init_(node*2,start,(start+end)/2);
    init_(node*2+1,(start+end)/2+1,end);
    tree[node]=arr[tree[node*2]]<arr[tree[node*2+1]]?tree[node*2]:tree[node*2+1];
}

int min_(int node,int start,int end,int left,int right) {
    if(left>end or right<start) {
        return -1;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    int tempA=min_(node*2,start,(start+end)/2,left,right);
    int tempB=min_(node*2+1,(start+end)/2+1,end,left,right);
    
    if(tempA==-1) {
        return tempB;
    }
    else if(tempB==-1) {
        return tempA;
    }
    return arr[tempA]<arr[tempB]?tempA:tempB;
}

void go_(int start,int end) {
    if(start==end) {
        ret=max(ret,arr[start]);
        return;
    }
    
    int idx=min_(1, 0, N-1, start, end);
    long long temp=arr[idx]*(end-start+1);
    ret=max(ret,temp);
    
    if(start<=idx-1) {
        go_(start, idx-1);
    }
    
    if(idx+1<=end) {
        go_(idx+1,end);
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
    
    init_(1, 0, N-1);
    go_(0, N-1);
    
    cout << ret << "\n";
    
    return 0;
}

#include <iostream>
#include <algorithm>

#define MAX_SIZE 1000004
using namespace std;

int N,M;
long long ret=-1000000004;
long long arr[MAX_SIZE];
long long tree[MAX_SIZE*4];

void update_(int node,int start,int end,long long idx,long long num) {
    
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]=num;
        return;
    }
    
    update_(node*2, start, (start+end)/2, idx, num);
    update_(node*2+1,(start+end)/2+1,end,idx,num);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

long long max_(int node,int start,int end,int left,int right) {
    
    if(left>end or right<start) {
        return -1000000004;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    long long tempA=max_(node*2,start,(start+end)/2,left,right);
    long long tempB=max_(node*2+1,(start+end)/2+1,end,left,right);
    
    if(tempA==-1000000004) {
        return tempB;
    }
    else if(tempB==-1000000004) {
        return tempA;
    }
    return max(tempA,tempB);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    arr[0]=0;
    for(int i=1;i<=N;i++) {
        cin >> arr[i];
        ret=max(ret,arr[i]);
    }
    
    update_(1,0, N,0, arr[0]);
    for(int i=1;i<M;i++) {
        update_(1, 0, N, i, arr[i]);
    }
    
    
    for(int i=1;i<=N;i++) {
        long long temp=max_(1,0,N,i-M,i-1)+arr[i];
        temp=max(temp,arr[i]);
        ret=max(ret,temp);
        update_(1,0,N,i,temp);
    }
    
    cout << ret << "\n";
    
    return 0;
}

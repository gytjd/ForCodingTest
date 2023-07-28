#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int arr[100004];
int tree[400004];

void init_(int node,int start,int end) {
    if(start==end) {
        tree[node]=arr[start];
        return;
    }
    
    init_(node*2,start,(start+end)/2);
    init_(node*2+1,(start+end)/2+1,end);
    tree[node]=min(tree[node*2],tree[node*2+1]);
}
void update_(int node,int start,int end,int idx,int num) {
    
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]=num;
        return;
    }
    
    update_(node*2, start, (start+end)/2, idx, num);
    update_(node*2+1, (start+end)/2+1, end, idx, num);
    tree[node]=min(tree[node*2],tree[node*2+1]);
}
int find_Min(int node,int start,int end,int left,int right) {
    if(left>end or right<start) {
        return 1000000004;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    int tempA=find_Min(node*2, start, (start+end)/2, left, right);
    int tempB=find_Min(node*2+1,(start+end)/2+1,end,left,right);
    return min(tempA,tempB);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    init_(1,0,N-1);
    
    cin >> M;
    for(int i=0;i<M;i++) {
        int A,B,C;
        cin >> A >> B >> C;
        if(A&1) {
            update_(1,0, N-1, B-1, C);
        }
        else {
            cout << find_Min(1,0,N-1,B-1,C-1) << "\n";
        }
    }
    
    return 0;
}

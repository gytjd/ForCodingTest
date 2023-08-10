#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[30004];
int tree[120004];
vector<int> ret;

void init_(int node,int start,int end) {
    
    if(start==end) {
        tree[node]+=1;
        return;
    }
    
    init_(node*2,start,(start+end)/2);
    init_(node*2+1, (start+end)/2+1, end);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int query_(int node,int start,int end,int num) {
    if(start==end) {
        return start;
    }
    
    if(tree[node*2]>=num) { // 왼쪽
        return query_(node*2, start, (start+end)/2, num);
    }
    else {
        return query_(node*2+1, (start+end)/2+1, end, num-tree[node*2]);
    }
}

void update_(int node,int start,int end,int idx) {
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]=0;
        return;
    }
    
    update_(node*2, start, (start+end)/2, idx);
    update_(node*2+1, (start+end)/2+1, end, idx);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    init_(1, 1, N);
    
    int tempN=N;
    for(int i=N-1;i>=0;i--) {
        
        if(arr[i]>=tempN) {
            cout << "NIE" << "\n";
            exit(0);
        }
        
//        cout << tempN-arr[i] << "\n";
        
        int temp=query_(1, 1, N, tempN-arr[i]);
        ret.push_back(temp);
        update_(1, 1, N, temp);
        tempN-=1;
    }
    
    reverse(ret.begin(), ret.end());
    for(int a:ret) {
        cout << a << "\n";
    }
    
    return 0;
}

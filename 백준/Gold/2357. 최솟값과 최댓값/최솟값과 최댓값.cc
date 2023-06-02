#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define INF 1000000000
using namespace std;


int N,M,H;
long long tree_Size;
vector<long long> v;

void display_(vector<long long> &tree) {
    for(int i=1;i<tree_Size;i++) {
        cout << tree[i] << " ";
    }
    cout << "\n";
}

void init_(vector<long long> &tree,int node,int start,int end,int mode) {
    
//    cout << start << " " << end << " " << node << "\n";
    
    if(start==end) {
        tree[node]=v[start];
    }
    else {
        init_(tree,node*2,start,(start+end)/2,mode);
        init_(tree,node*2+1,(start+end)/2+1,end,mode);
        
        if(mode) {
            tree[node]=max(tree[node*2],tree[node*2+1]);
        }
        else {
            tree[node]=min(tree[node*2],tree[node*2+1]);
        }
    }
}

long long max_Tree(vector<long long> &tree,int node,int start,int end,int left,int right,int mode) {
    
//    cout << start << " " << end << "\n";
    
    if(left>end or right<start) {
        
        if(mode) {
            return 0;
        }
        else {
            return INF;
        }
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    long long tempA=max_Tree(tree, node*2, start, (start+end)/2, left, right,mode);
    long long tempB=max_Tree(tree, node*2+1, (start+end)/2+1, end, left, right,mode);
    
    if(mode) {
        return max(tempA,tempB);
    }
    else {
        return min(tempA,tempB);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        long long data;
        cin >> data;
        v.push_back(data);
    }
    
    H=ceil(log2(N));
    tree_Size=(1<<(H+1));
    vector<long long> tree_A(tree_Size);
    vector<long long> tree_I(tree_Size,INF);
    
    init_(tree_A, 1, 0, N-1,1);
    init_(tree_I,1,0,N-1,0);
    
//    display_(tree_I);
    
    for(int i=0;i<M;i++) {
        int left,right;
        cin >> left >> right;
        cout << max_Tree(tree_I, 1, 0, N-1, left-1, right-1, 0) << " " << max_Tree(tree_A, 1, 0, N-1, left-1, right-1, 1) <<  "\n";
    }
    
    return 0;
}

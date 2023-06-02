#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int h;
long long tree_Size;

int N,M,K;
vector<long long> v;
 
void display_(vector<long long> &tree) {
    for(int i=1;i<tree_Size;i++) {
        cout << tree[i] << " ";
    }
    cout << "\n";
}
void init_(vector<long long> &tree,int node,int start,int end) {
    
//    cout << start << " " << end << " " << node << " " << "\n";
    if(start==end) {
        tree[node]=v[start];
        return;
    } else {
        init_(tree,node*2,start,(start+end)/2);
        init_(tree,node*2+1,(start+end)/2+1,end);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
}

long long sum_(vector<long long> &tree,int node,int start,int end,int left,int right) {
    
//    cout << start << " " << end << " " <<left << " " << right << "\n";
    
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and end<=right) {
        return tree[node];
    }
    
    long long tempA=sum_(tree, node*2, start, (start+end)/2, left, right);
    long long tempB=sum_(tree,node*2+1,(start+end)/2+1,end,left,right);
    return tempA+tempB;
}

void update_(vector<long long> &tree,int node,int start,int end,int idx,long long temp) {
    
//    cout << start << " " << end << "\n";
    
    if(idx<start or idx>end) {
        return;
    }
    tree[node]+=temp;
    
    if(start!=end) {
        update_(tree, node*2, start, (start+end)/2, idx, temp);
        update_(tree, node*2+1, (start+end)/2+1, end, idx, temp);
    }
}

void update_r(vector<long long> &tree,int node,int start,int end,int idx,long long temp) {
    long long diff=temp-v[idx];
    v[idx]=temp;
    update_(tree, node, start, end, idx, diff);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    
    cin >> N >> M >> K;
    
    h=ceil(log2(N));
    tree_Size=(1<<(h+1));
    vector<long long> tree(tree_Size);
    
    for(int i=0;i<N;i++) {
        long long data;
        cin >> data;
        v.push_back(data);
    }
    
    init_(tree,1,0,N-1);
//    display_(tree);
    M+=K;
    
    for(int i=0;i<M;i++) {
        int data;
        cin >> data;
        
        if(data==1) {
            int a;
            long long b;
            cin >> a >> b;
            update_r(tree, 1, 0, N-1, a-1, b);
//            display_(tree);
        }
        else if(data==2) {
            int a,b;
            cin >> a >> b;
            cout << sum_(tree, 1, 0, N-1, a-1, b-1) << "\n";
        }
    }
    
    return 0;
}

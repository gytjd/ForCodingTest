#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N,H;
long long treeSize;
vector<pair<int, int>> v;

void display_(vector<long long> &tree) {
    for(int i=1;i<treeSize;i++) {
        cout << tree[i] << " ";
    }
    cout << "\n";
}

bool cmp(pair<int, int> a,pair<int, int> b) {
    if(a.first==b.first) {
        return a.second<b.second;
    }
    return a.first>b.first;
}

long long sum_(vector<long long> &tree,int node,int start,int end,int left,int right) {
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    long long tempA=sum_(tree, node*2, start, (start+end)/2, left, right);
    long long tempB=sum_(tree,node*2+1,(start+end)/2+1,end,left,right);
    return max(tempA,tempB);
}

void update_(vector<long long> &tree,int node,int start,int end,int idx,long long temp) {
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]=temp;
        return;
    }
    
    update_(tree, node*2, start, (start+end)/2, idx, temp);
    update_(tree, node*2+1, (start+end)/2+1, end, idx, temp);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    H=ceil(log2(N));
    treeSize=(1<<(H+1));
    vector<long long> tree(treeSize,0);
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back({data,i});
    }
    
    sort(v.begin(), v.end(),cmp);
    
    long long temp=0;
    for(int i=0;i<N;i++) {
        temp=sum_(tree, 1, 0, N-1, v[i].second, N-1);
        update_(tree, 1, 0, N-1, v[i].second, temp+1);
    }
    
    cout << tree[1] << "\n";
    
    return 0;
}

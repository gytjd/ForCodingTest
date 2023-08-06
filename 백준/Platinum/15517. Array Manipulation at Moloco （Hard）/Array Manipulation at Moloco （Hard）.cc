#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<long long, long long>> v;

long long arr[1000004];
long long tree[4000004];

void update_(int node, int start,int end,long long idx) {
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]=1;
        return;
    }
    
    update_(node*2, start, (start+end)/2, idx);
    update_(node*2+1, (start+end)/2+1, end, idx);
    tree[node]=tree[node*2]+tree[node*2+1];
}

long long sum_(int node,int start,int end,long long left,long long right) {
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    long long tempA=sum_(node*2, start, (start+end)/2, left, right);
    long long tempB=sum_(node*2+1,(start+end)/2+1,end,left,right);
    return tempA+tempB;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        long long data;
        cin >> data;
        v.push_back({data,i});
    }
    
    sort(v.begin(), v.end());
    
    for(pair<long long,long long> temp:v) {
        update_(1, 0, N-1, temp.second);
        arr[temp.second]=sum_(1, 0, N-1, 0, temp.second-1);
    }
    
    for(int i=0;i<N;i++) {
        cout << arr[i] << "\n";
    }
    
    return 0;
}

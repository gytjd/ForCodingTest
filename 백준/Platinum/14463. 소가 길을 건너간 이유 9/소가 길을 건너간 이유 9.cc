#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX_SIZE 50004

using namespace std;

long long N;
long long idx[MAX_SIZE*2];
long long tree[MAX_SIZE*8];
vector<pair<long long, long long>> v;

void update_(long long node,long long start,long long end,long long idx) {
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]+=1;
        return;
    }
    
    update_(node*2, start, (start+end)/2, idx);
    update_(node*2+1, (start+end)/2+1, end, idx);
    tree[node]=tree[node*2]+tree[node*2+1];
}

long long sum_(long long node,long long start,long long end,long long left,long long right) {
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    long long tempA=sum_(node*2, start, (start+end)/2, left, right);
    long long tempB=sum_(node*2+1, (start+end)/2+1, end, left, right);
    return tempA+tempB;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(long long i=1;i<=2*N;i++) {
        long long data;
        cin >> data;
        if(idx[data]==0) {
            idx[data]=i;
        }
        else {
            v.push_back({idx[data],i});
        }
    }
    
    long long ret=0;
    sort(v.begin(), v.end());
    for(pair<long long, long long> temp:v) {
//        cout << temp.first << " " << temp.second << "\n";
        
        ret+=sum_(1, 1, 2*N, temp.first, temp.second);
        update_(1, 1, 2*N, temp.second);
    }
    cout << ret << "\n";
    return 0;
}


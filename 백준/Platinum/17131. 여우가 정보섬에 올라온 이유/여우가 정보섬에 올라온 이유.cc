#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 200000
#define MOD 1000000007

using namespace std;

long long N;
long long tree[MAX_SIZE*8];
vector<pair<long long, long long>> v;

bool cmp(pair<long long, long long> &a,pair<long long, long long> &b) {
    if(a.second==b.second) {
        return a.first<b.first;
    }
    return a.second>b.second;
}

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
    for(long long i=0;i<N;i++) {
        long long x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    
    sort(v.begin(),v.end(),cmp);
    
    long long prev,curr;
    vector<long long> tempV;
    prev=v[0].second;
    tempV.push_back(v[0].first);
    
    long long ret=0;
    
    for(long long i=1;i<N;i++) {
        curr=v[i].second;
        if(curr!=prev) {
            for(long long t:tempV) {
                update_(1, 0, MAX_SIZE*2, t+MAX_SIZE);
            }
            tempV.clear();
        }
        
        long long tempA=sum_(1, 0, MAX_SIZE*2, 0, v[i].first-1+MAX_SIZE)%MOD;
        long long tempB=sum_(1, 0, MAX_SIZE*2, v[i].first+1+MAX_SIZE, MAX_SIZE*2)%MOD;
//        cout <<"#" << " " <<  tempA << " " << tempB << "\n";
        
        ret+=(tempA*tempB)%MOD;
        ret%=MOD;
        tempV.push_back(v[i].first);
        prev=curr;
    }
    
    cout << ret%MOD << "\n";

    return 0;
}

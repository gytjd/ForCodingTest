#include <iostream>
#define MAX_SIZE 200004
#define MOD 1000000007
using namespace std;

int N;
long long arr[MAX_SIZE];
pair<long long, long long> tree[MAX_SIZE*4]; // first 는 개수 second 는 합으로 하자

void update_(int node,int start,int end,long long idx) {
    
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node].first+=1;
        tree[node].second+=idx;
        return;
    }
    
    update_(node*2, start, (start+end)/2,idx);
    update_(node*2+1,(start+end)/2+1,end,idx);
    tree[node].first=tree[node*2].first+tree[node*2+1].first;
    tree[node].second=tree[node*2].second+tree[node*2+1].second;
}

pair<long long, long long> sum_(int node,int start,int end,long long left,long long right) {
    
    if(left>end or right<start) {
        return {0,0};
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    pair<long long, long long> tempA=sum_(node*2, start, (start+end)/2, left, right);
    pair<long long, long long> tempB=sum_(node*2+1, (start+end)/2+1, end, left, right);
    return {tempA.first+tempB.first,tempA.second+tempB.second};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    long long ret=1;
    update_(1, 0, MAX_SIZE, arr[0]);
    for(int i=1;i<N;i++) {
        pair<long long,long long> tempA=sum_(1, 0, MAX_SIZE, 0, arr[i]-1);
        pair<long long,long long> tempB=sum_(1, 0, MAX_SIZE, arr[i]+1, MAX_SIZE);
        update_(1, 0, MAX_SIZE, arr[i]);
        
        long long retA=((arr[i]*tempA.first)-tempA.second);
        retA=retA%MOD;
        long long retB=(tempB.second-(arr[i]*tempB.first));
        retB=retB%MOD;
        
        long long result=(retA+retB)%MOD;
        ret=ret*result;
        ret=ret%MOD;
    }
    
    cout << ret%MOD << "\n";
    
    return 0;
}

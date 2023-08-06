#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

long long ret;
long long N;
map<string, long long> m;

vector<pair<long long, long long>> v;
long long arr[100004];
long long tree[400004];

void update_(long long node,long long start,long long end,long long idx) {
    
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]=1;
        return;
    }
    
    update_(node*2, start, (start+end)/2, idx);
    update_(node*2+1,(start+end)/2+1,end,idx);
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
    
    while(true) {
        cin >> N;
        if(!N) {
            break;
        }
        
        m.clear();
        ret=0;
        v.clear();
        memset(arr, 0, sizeof(arr));
        memset(tree, 0, sizeof(tree));
        
        for(long long i=0;i<N;i++) {
            string a;
            cin >> a;
            m[a]=i;
        }
        
        for(long long i=0;i<N;i++) {
            string a;
            cin >> a;
            v.push_back({m[a],i});
        }
        
        sort(v.begin(), v.end());
        
        for(pair<long long, long long> temp:v) {
            update_(1, 0, N-1, temp.second);
            ret+=sum_(1, 0, N-1, temp.second+1, N-1);
        }
        
        cout << ret << "\n";
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

#define MAX_SIZE 500004
using namespace std;

int N;
vector<int> w;
vector<int> v;
vector<pair<int, int>> temp;
int tree[MAX_SIZE*4];
map<int, int> m;

void update_(int node,int start,int end,int idx) {
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]=1;
        return;
    }
    
    update_(node*2,start,(start+end)/2,idx);
    update_(node*2+1, (start+end)/2+1, end, idx);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int query_(int node,int start,int end,int left,int right) {
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    int tempA=query_(node*2, start, (start+end)/2, left, right);
    int tempB=query_(node*2+1, (start+end)/2+1, end, left, right);
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
        
        memset(tree, 0, sizeof(tree));
        w.clear();
        v.clear();
        temp.clear();
        m.clear();
        
        for(int i=0;i<N;i++) {
            int data;
            cin >> data;
            v.push_back(data);
            w.push_back(data);
        }
        sort(v.begin(), v.end());
        for(int i=0;i<N;i++) {
            temp.push_back({i,v[i]});
        }

        for(pair<int, int> a:temp) {
            m[a.second]=a.first;
        }
        
        long long ret=0;
        for(int i=N-1;i>=0;i--) {
            update_(1, 0, N-1, m[w[i]]);
            ret+=query_(1, 0, N-1, 0, m[w[i]]-1);
        }
        
        cout << ret << "\n";
    }
    
    return 0;
}

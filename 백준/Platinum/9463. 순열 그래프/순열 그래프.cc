#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int T;
int N;

long long ret;
vector<pair<int, int>> v;
int arr[100004];
int tree[400004];

void update_(int node,int start,int end,int idx) {
    
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

int sum_(int node,int start,int end,int left,int right) {
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    int tempA=sum_(node*2,start,(start+end)/2,left,right);
    int tempB=sum_(node*2+1,(start+end)/2+1,end,left,right);
    return tempA+tempB;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int q=0;q<T;q++) {
        cin >> N;
        memset(arr,0,sizeof(arr));
        memset(tree,0,sizeof(tree));
        v.clear();
        ret=0;
        
        for(int i=0;i<N;i++) {
            int data;
            cin >> data;
            arr[data]=i;
        }
        
        for(int i=0;i<N;i++) {
            int data;
            cin >> data;
            v.push_back({arr[data],i});
        }
        
        sort(v.begin(), v.end());
        
        for(pair<int, int> temp:v) {
//            cout << temp.first << " " << temp.second << "\n";
            update_(1, 0, N-1, temp.second);
            ret+=sum_(1, 0, N-1, temp.second+1, N-1);
        }
        
        cout << ret << "\n";
    }
    
    return 0;
}

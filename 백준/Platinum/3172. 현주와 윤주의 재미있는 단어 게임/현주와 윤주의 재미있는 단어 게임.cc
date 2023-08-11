#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define MAX_SIZE 100004
using namespace std;

int N;
pair<int, int> arr[MAX_SIZE];
int tree[MAX_SIZE*4];

vector<pair<string, int>> v1;
vector<pair<string, int>> v2;

void update_(int node,int start,int end,int idx) {
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

int sum_(int node,int start,int end,int left,int right) {
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    int tempA=sum_(node*2, start, (start+end)/2, left, right);
    int tempB=sum_(node*2+1, (start+end)/2+1, end, left, right);
    return tempA+tempB;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        v1.push_back({a,i});
        reverse(a.begin(), a.end());
        v2.push_back({a,i});
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(),v2.end());
    
    for(int i=0;i<N;i++) {
        arr[v1[i].second].first=i;
    }
    
    for(int i=0;i<N;i++) {
        arr[v2[i].second].second=i;
    }
    sort(arr, arr+N);
    
    long long ret=0;
    for(int i=0;i<N;i++) {
//        cout << arr[i].first << " " << arr[i].second << "\n";
        ret+=sum_(1, 0, N-1, arr[i].second+1, N-1);
        update_(1, 0, N-1, arr[i].second);
    }
    
    cout << ret << "\n";
    
    return 0;
}

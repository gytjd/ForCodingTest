#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &a,pair<int, int> &b) {
    return a.first>b.first;
}

int N;
int arr[100004];
int tree[400004];

vector<pair<int, int>> v;

void init_(int node,int start,int end) {
    if(start==end) {
        tree[node]=1;
        return;
    }
    
    init_(node*2,start,(start+end)/2);
    init_(node*2+1,(start+end)/2+1,end);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void update_(int node,int start,int end,int idx,int num) {
    
    if(start==end) {
        tree[node]=0;
        arr[start]=num;
        return;
    }
    
    if(tree[node*2]<=idx) { // 오른쪽으로 가야함
        update_(node*2+1,(start+end)/2+1,end,idx-tree[node*2],num);
    }
    else {
        update_(node*2, start, (start+end)/2,idx, num);
    }
    tree[node]=tree[node*2]+tree[node*2+1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=1;i<=N;i++) {
        int data;
        cin >> data;
        v.push_back({i,i-(data+1)});
    }
    sort(v.begin(), v.end(), cmp);
    init_(1,0,N-1);
    
    for(pair<int, int> temp:v) {
//        cout << temp.first << " " << temp.second << "\n";
        update_(1, 0, N-1, temp.second, temp.first);
    }
    
    for(int i=0;i<N;i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}

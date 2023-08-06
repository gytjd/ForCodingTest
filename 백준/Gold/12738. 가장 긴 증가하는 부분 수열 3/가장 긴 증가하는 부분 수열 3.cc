#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 1000004
using namespace std;

int ret;
int N;
int arr[MAX_SIZE];
int tree[MAX_SIZE*4];

vector<pair<int, int>> v;

bool cmp(pair<int, int> &a,pair<int, int> &b) {
    
    if(a.second==b.second) {
        return a.first>b.first;
    }
    return a.second<b.second;
}

void update_(int node,int start,int end,int idx,int num) {
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]=num;
        return;
    }
    
    update_(node*2, start, (start+end)/2, idx,num);
    update_(node*2+1, (start+end)/2+1,end, idx,num);
    tree[node]=max(tree[node*2],tree[node*2+1]);
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
    return max(tempA,tempB);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back({i,data});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(pair<int, int> temp:v) {
        int max_Idx=sum_(1, 0, N-1, 0, temp.first-1);
        update_(1, 0, N-1,temp.first,max_Idx+1);
        ret=max(ret,max_Idx+1);
    }
    
    cout << ret << "\n";
    return 0;
}

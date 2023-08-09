#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 100004
using namespace std;

int N;
int arr[MAX_SIZE];
int idx[MAX_SIZE];
int tree[MAX_SIZE*4];

vector<int> temp;
vector<int> ret;
 
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
    
    int tempA=sum_(node*2, start, (start+end)/2, left, right);
    int tempB=sum_(node*2+1,(start+end)/2+1,end,left,right);
    return tempA+tempB;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        idx[arr[i]]=i;
    }
    
    int tempA=1;
    int tempB=N;
    
    while(tempA<=tempB) {
        if(tempA==tempB) {
            temp.push_back(tempA++);
        }
        else {
            temp.push_back(tempA++);
            temp.push_back(tempB--);
        }
    }
    reverse(temp.begin(), temp.end());
    
    for(int i=0;i<temp.size();i++) {
//        cout << temp[i] << " "  << idx[temp[i]] << "\n";
        if(temp[i]<=(N+1)/2)  { // 자기보다 큰수
            ret.push_back(sum_(1, 0, N-1, 0, idx[temp[i]]-1));
        }
        else { // 자기보다 작은수
            ret.push_back(sum_(1, 0, N-1, idx[temp[i]]+1, N-1));
        }
        update_(1, 0, N-1, idx[temp[i]]);
    }
    
    reverse(ret.begin(), ret.end());
    for(int a:ret) {
        cout << a << "\n";
    }
    
    return 0;
}

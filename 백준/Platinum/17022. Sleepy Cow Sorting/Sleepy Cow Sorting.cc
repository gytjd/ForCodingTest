#include <iostream>

#define MAX_SIZE 100004
using namespace std;

int thershold;
int N;
int arr[MAX_SIZE];
int tree[MAX_SIZE*4];

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
        cin >> arr[i];
    }
    
    for(int i=N-1;i>=0;i--) {
        if(arr[i]<arr[i-1]) {
            thershold=i;
            break;
        }
    }
    
    for(int i=thershold;i<N;i++) {
        update_(1, 0, N-1, arr[i]);
    }
    
    cout << thershold << "\n";
    for(int i=0;i<thershold;i++) {
        update_(1, 0, N-1, arr[i]);
        cout << sum_(1, 0, N-1, 0, arr[i]-1)+(thershold-i-1) << " ";
    }
    cout << "\n";
    
    return 0;
}

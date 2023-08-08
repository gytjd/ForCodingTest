#include <iostream>
#include <cstring>

#define MAX_SIZE 100004
using namespace std;

int T,N,M;
int idx[MAX_SIZE];
int tree[MAX_SIZE*8];

void update_(int node,int start,int end,int idx,int num) {
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]=num;
        return;
    }
    
    update_(node*2, start, (start+end)/2, idx,num);
    update_(node*2+1, (start+end)/2+1, end, idx,num);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int sum_(int node,int start,int end,int left,int right) {
    
//    cout << start << " " << end << "\n";
    
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
    
    cin >> T;
    for(int q=0;q<T;q++) {
        cin >> N >> M;
        
        int temp=0;
        memset(idx, 0, sizeof(idx));
        memset(tree,0,sizeof(tree));
        
        
        for(int i=N;i>0;i--) {
            idx[i]=temp;
            update_(1, 0, N+M-1, temp++, 1);
        }
        
        temp=N;
        for(int i=0;i<M;i++) {
            int data;
            cin >> data;
            cout << sum_(1, 0, N+M-1, idx[data]+1, temp-1) << " ";
            
            update_(1, 0, N+M-1, idx[data], 0);
            update_(1, 0, N+M-1, temp, 1);
            idx[data]=temp++;
        }
        cout << "\n";
    }
}

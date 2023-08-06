#include <iostream>
#include <cstring>
using namespace std;

int tempN;
int N,K,M;
int tree[40004];

void init_(int node,int start,int end) {
    if(start==end) {
        tree[node]=1;
        return;
    }
    
    init_(node*2,start,(start+end)/2);
    init_(node*2+1,(start+end)/2+1,end);
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

void update_(int node,int start,int end,int idx) {
    
    
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]=0;
        return;
    }
    
    update_(node*2, start, (start+end)/2,idx);
    update_(node*2+1, (start+end)/2+1, end, idx);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int num_(int node,int start,int end,int num) {
    
//    cout << start << " " << end << " " << num << " " << tree[node*2] << "\n";
    
    if(start==end) {
        return start;
    }
    
    if(tree[node*2]>=num) { // 왼쪽으로
        return num_(node*2, start, (start+end)/2, num);
    }
    else {
        return num_(node*2+1,(start+end)/2+1,end,num-tree[node*2]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(true) {
        cin >> N >> K >> M;
        if(!N and !K and !M) {
            break;
        }
        
        memset(tree, 0, sizeof(tree));
        
        tempN=N;
        init_(1, 1, N);
        update_(1, 1, N, M);
        tempN-=1;
        
        while(tempN!=0) {
            int temp=(K+sum_(1, 1, N, 0, M-1))%tempN;
            if(temp==0) {
                temp=tempN;
            }
            
            M=num_(1, 1, N, temp);
            update_(1, 1, N, M);
            tempN-=1;
        }
        
        cout << M << "\n";
    }
}

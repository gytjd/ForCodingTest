#include <iostream>
#include <cmath>
#define MAX_SIZE 300004
using namespace std;

int N,M;
int arr[MAX_SIZE];
long long treeA[MAX_SIZE*4]; // 짝수
long long treeB[MAX_SIZE*4]; // 홀수

void init_(int node,int start,int end) {
    
    if(start==end) {
        if(start%2==0) {
            treeA[node]=arr[start];
        }
        else {
            treeB[node]=arr[start];
        }
        return;
    }
    init_(node*2, start, (start+end)/2);
    init_(node*2+1,(start+end)/2+1,end);
    treeA[node]=treeA[node*2]+treeA[node*2+1];
    treeB[node]=treeB[node*2]+treeB[node*2+1];
}

long long sum_A(int node,int start,int end,int left,int right) {
    
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return treeA[node];
    }
    
    long long tempA=sum_A(node*2, start, (start+end)/2, left, right);
    long long tempB=sum_A(node*2+1, (start+end)/2+1, end, left,  right);
    return tempA+tempB;
}

long long sum_B(int node,int start,int end,int left,int right) {
    
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return treeB[node];
    }
    
    long long tempA=sum_B(node*2, start, (start+end)/2, left, right);
    long long tempB=sum_B(node*2+1, (start+end)/2+1, end, left,  right);
    return tempA+tempB;
    
}

void update_A(int node,int start,int end,int idx,int num) {
    
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        treeA[node]+=num;
        return;
    }
    
    update_A(node*2, start, (start+end)/2, idx, num);
    update_A(node*2+1,(start+end)/2+1,end,idx,num);
    treeA[node]=treeA[node*2]+treeA[node*2+1];
}

void update_B(int node,int start,int end,int idx,int num) {
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        treeB[node]+=num;
        return;
    }
    
    update_B(node*2, start, (start+end)/2, idx, num);
    update_B(node*2+1,(start+end)/2+1,end,idx,num);
    treeB[node]=treeB[node*2]+treeB[node*2+1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    init_(1, 0, N-1);
    
    for(int i=0;i<M;i++) {
        int A,B,C;
        cin >> A >> B >> C;
        if(A&1) {
            long long tempA=sum_A(1,0,N-1,B-1,C-1);
            long long tempB=sum_B(1,0,N-1,B-1,C-1);
            cout << abs(tempA-tempB) << "\n";
        }
        else {
            if((B-1)%2==0) {
                update_A(1, 0, N-1, B-1, C);
            }
            else {
                update_B(1, 0, N-1, B-1, C);
            }
        }
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_SIZE 100004

using namespace std;

struct Node_One {
    int num,to,data;
};

struct Node_Two {
    int num,from,to;
};

int N,M;
long long arr[MAX_SIZE];
long long tree[MAX_SIZE*4];
long long ret[MAX_SIZE];
vector<Node_One> v1;
vector<Node_Two> v2[MAX_SIZE]; // 2명령어

void init_(int node,int start,int end) {
    if(start==end) {
        tree[node]=arr[start];
        return;
    }
    
    init_(node*2, start, (start+end)/2);
    init_(node*2+1,(start+end)/2+1,end);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void update_(int node,int start,int end,int idx,int num) {
    
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node]=num;
        return;
    }
    
    update_(node*2, start, (start+end)/2, idx, num);
    update_(node*2+1,(start+end)/2+1,end,idx,num);
    tree[node]=tree[node*2]+tree[node*2+1];
}

long long sum_(int node,int start,int end,int left,int right) {
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    long long tempA=sum_(node*2,start,(start+end)/2,left,right);
    long long tempB=sum_(node*2+1,(start+end)/2+1,end,left,right);
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
    init_(1, 0, N-1);
    
    cin >> M;
    int count_T=0;
    int count_A=1;
    for(int i=0;i<M;i++) {
        int A,B,C,D;
        cin >> A;
        if(A&1) {
            cin >> B >> C;
            v1.push_back({count_A++,B-1,C});
        }
        else {
            cin >> B >> C >> D;
            v2[B].push_back({count_T++,C-1,D-1});
        }
    }
    
    for(Node_Two temp:v2[0]) {
//        cout << temp.num << " " << temp.from << " " << temp.to << "\n";
        ret[temp.num]=sum_(1, 0, N-1, temp.from, temp.to);
    }
    for(Node_One temp:v1) {
//        cout << temp.num << " " << temp.to << " " << temp.data << "\n";
        update_(1, 0, N-1, temp.to, temp.data);
        for(Node_Two tempA:v2[temp.num]) {
            ret[tempA.num]=sum_(1, 0, N-1, tempA.from, tempA.to);
        }
    }
    
    for(int i=0;i<count_T;i++) {
        cout << ret[i] << "\n";
    }
    return 0;
}

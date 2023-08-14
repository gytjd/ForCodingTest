#include <iostream>
#include <algorithm>
#define MAX_SIZE 50004

using namespace std;

int N,M;
int arr[MAX_SIZE];
pair<int, int> tree[MAX_SIZE*4]; // first = max/ second = min

void init_(int node,int start,int end) {
    if(start==end) {
        tree[node].first=arr[start];
        tree[node].second=arr[start];
        return;
    }
    
    init_(node*2, start, (start+end)/2);
    init_(node*2+1, (start+end)/2+1, end);
    tree[node].first=max(tree[node*2].first,tree[node*2+1].first);
    tree[node].second=min(tree[node*2].second,tree[node*2+1].second);
}

int query_A(int node,int start,int end,int left,int right) {
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node].first;
    }
    
    int tempA=query_A(node*2, start, (start+end)/2, left, right);
    int tempB=query_A(node*2+1, (start+end)/2+1, end, left, right);
    return max(tempA,tempB);
}

int query_B(int node,int start,int end,int left,int right) {
    
//    cout << start << " " << end << "\n";
    
    if(left>end or right<start) {
        return 1000004;
    }
    
    if(left<=start and right>=end) {
        return tree[node].second;
    }
    
    int tempA=query_B(node*2, start, (start+end)/2, left, right);
    int tempB=query_B(node*2+1, (start+end)/2+1, end, left, right);
    return min(tempA,tempB);
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
        int A,B;
        cin >> A >> B;
        int tempA=query_A(1, 0, N-1, A-1, B-1);
        int tempB=query_B(1, 0, N-1, A-1, B-1);
        cout << tempA-tempB << "\n";
    }
    
    return 0;
}

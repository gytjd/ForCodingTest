#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ret;
int N;
int arr[1000004];
long long tree[2000004];

vector<pair<int, int>> v;

void update_(int node, int start, int end, int idx) {
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
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        arr[data] = i;
    }

    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        v.push_back({arr[data],i});
    }
    
    sort(v.begin(), v.end());
    //  여기서 부터 하나씩 자기보다 큰 숫자의 개수 더해줘야함

    for (pair<int, int> temp : v) {
        update_(1, 0, N-1, temp.second);
        ret+=sum_(1, 0, N-1, temp.second+1, N-1);
    }

    
    cout << ret << "\n";
    
    
    return 0;

}

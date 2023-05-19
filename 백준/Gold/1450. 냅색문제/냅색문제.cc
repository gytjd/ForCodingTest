#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,C;
int ret;
int arr[34];

vector<int> v1;
vector<int> v2;

void go_(int idx,int n,int sum,vector<int> &temp) {
    
    if(sum>C) {
        return;
    }
    if(idx>n) {
        temp.push_back(sum);
        return;
    }
    
    go_(idx+1, n, sum,temp);
    go_(idx+1, n, sum+arr[idx],temp);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> C;
    
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    go_(0, N/2-1, 0,v1);
    go_(N/2, N-1, 0,v2);
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(),v2.end());
    
    for(int a:v2) {
        
        if(C-a>=0) {
            ret+=upper_bound(v1.begin(), v1.end(), C-a)-v1.begin();
        }
    }
    
    cout << ret << "\n";
    
    
    return 0;
}

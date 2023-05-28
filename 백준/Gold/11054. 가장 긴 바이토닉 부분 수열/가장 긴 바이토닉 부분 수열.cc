#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
int dp_A[1004];
int dp_B[1004];

void go_() {
    
    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            if(v[j]<v[i]) {
                dp_A[i]=max(dp_A[i],dp_A[j]+1);
            }
        }
    }
    
    
    for(int i=N-2;i>=0;i--) {
        for(int j=N-1;j>i;j--) {
            if(v[i]>v[j]) {
                dp_B[i]=max(dp_B[i],dp_B[j]+1);
            }
        }
    }
    
    int ret=0;
    for(int i=0;i<N;i++) {
        
        int temp=0;
        for(int j=i+1;j<N;j++) {
            if(v[i]>v[j]) {
                temp=max(temp,dp_B[j]);
            }
        }
        ret=max(ret,temp+dp_A[i]);
    }
    
    cout << ret << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
        
        dp_A[i]=1;
        dp_B[i]=1;
    }
    
    go_();
    
    return 0;
}

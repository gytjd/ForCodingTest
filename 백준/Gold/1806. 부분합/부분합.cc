#include <iostream>
using namespace std;

int N,M;
int arr[100004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        cin >> arr[i];
    }
    
    for(int i=2;i<=N;i++) {
        arr[i]+=arr[i-1];
    }
    
    int ret=987654321;
    int low=0;
    int high=0;
    
    while(low<=high and high<=N) {
        if(arr[high]-arr[low]>=M) {
            ret=min(ret,high-low);
            low+=1;
        }
        else {
            high+=1;
        }
    }
    
    if(ret==987654321) {
        cout << 0 << "\n";
    }
    else {
        cout << ret << "\n";
    }
    
    return 0;
}


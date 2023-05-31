#include <iostream>
using namespace std;

int N;
int arr[1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=1;i<=N;i++) {
        cin >> arr[i];
    }
    
    int ret=0;
    int sum=0;
    for(int i=2;i<=N;i++) {
        if(arr[i]>arr[i-1]) {
            sum+=(arr[i]-arr[i-1]);
            ret=max(ret,sum);
        }
        else {
            sum=0;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}

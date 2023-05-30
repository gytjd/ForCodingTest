#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> v;
long long arr[100004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    
    for(int i=1;i<N;i++) {
        arr[i]+=arr[i-1];
    }
    
    long long ret=0;
    for(int i=1;i<N;i++) {
        ret+=(arr[i-1]*v[i]);
    }
    
    cout << ret << "\n";
    
    return 0;
}

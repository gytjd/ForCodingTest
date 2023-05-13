#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
long long low=1,high,mid,temp;
long long count_T,ret,tot;

vector<long long> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        cin >> temp;
        high=max(temp, high);
        v.push_back(temp);
    }
    
    while(low<=high) {
        mid=(low+high)/2;
//        cout << mid << "\n";
        count_T=0;
        
        for(long long a:v) {
            count_T+=(a/mid);
        }
        
        if(count_T<M) {
            high=mid-1;
        }
        else {
            ret=mid;
            low=mid+1;
        }
    }
    
//    cout << ret << "\n";
    
    for(long long a:v) {
        tot+=a;
    }
    cout << tot-(ret*M) << "\n";
    
    return 0;
}

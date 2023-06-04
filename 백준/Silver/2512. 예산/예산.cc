#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
long long low=1,high,mid;
long long ret;

vector<long long> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        long long data;
        cin >> data;
        high=max(high,data);
        v.push_back(data);
    }
    
    long long sum=0;
    
    cin >> M;
    
    while(low<=high) {
        sum=0;
        mid=(low+high)/2;
//        cout << mid << "\n";
        for(long long temp:v) {
            if(temp>mid) {
                sum+=mid;
            }
            else {
                sum+=temp;
            }
        }
        
//        cout << sum << "\n\n";
        
        if(sum<=M) {
            ret=max(ret, mid);
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
    
}
